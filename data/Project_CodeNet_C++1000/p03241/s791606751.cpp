#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const ll MOD = 1e9+7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;
 
 //使い方
 int main() {
     ll n,m;
     cin >> n >> m;
     ll ans = 1;
     for(int i=m/n;i>1;i--){
         if(m%i!=0) continue;
         if(i*n<=m){
             ans = i;
             break;
         }
     }
     cout << ans << endl;
     return 0;
 }