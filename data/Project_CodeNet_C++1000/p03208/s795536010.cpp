
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
     ll n, k;
     cin >> n >> k;
     vector<ll> h(n);
     rep(i,n) cin >> h.at(i);
     sort(all(h));
     ll ans=1e9;
     for(int i=0; i<=n-k; i++){
         ll diff = h.at(i+k-1) - h.at(i);
         ans = min(ans,diff);
     }
     cout << ans << endl;

     
}