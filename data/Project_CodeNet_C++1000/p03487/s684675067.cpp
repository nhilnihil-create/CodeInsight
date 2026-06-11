#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    vector<LL> A(N);
    REP(i,N)cin>>A[i];

    map<LL, LL> count;
    REP(i, N){
        auto itr = count.find(A[i]);
        if(itr != count.end()){
            count[A[i]] += 1;
        }else{
            count[A[i]] = 1;
        }
    }

    LL ans = 0;
    for(auto itr=count.begin(); itr!=count.end(); ++itr){
        LL num = itr->first;
        LL c = itr->second;
        if(c < num){
            ans += c;
        }else{
            ans += c-num;
        }
    }

    cout << ans << endl;
    return 0;
}