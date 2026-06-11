#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    LL K, A, B;
    cin >> K >> A >> B;

    if(A + 2 >= B){
        cout << 1 + K << endl;
        return 0;
    }

    if((K+1)/(A+2) == 0){
        cout << 1 + K << endl;
        return 0;
    }

    LL ans = B;
    LL count =  A + 1;
    ans += (K - count) / 2 * (B - A);
    ans += (K - count) % 2;
    cout << ans << endl;
    return 0;
}