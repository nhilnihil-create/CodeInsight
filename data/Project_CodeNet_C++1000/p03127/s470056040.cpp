#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

LL gcd(LL val1, LL val2);


int main(){
    int N;
    cin >> N;
    vector<LL> A(N);
    REP(i,N)cin>>A[i];

    LL g = A[0];
    FOR(i, 1, N){
        g = gcd(A[i], g);
    }

    cout << g << endl;
    return 0;

}

LL gcd(LL val1, LL val2){
    LL _val1 = max({val1, val2});
    LL _val2 = min({val1, val2});

    LL _val3 = _val1 % _val2;
    if(_val3==0){return _val2;}
    return gcd(_val2, _val3);
}