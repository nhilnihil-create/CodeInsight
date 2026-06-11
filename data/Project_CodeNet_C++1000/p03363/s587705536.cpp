#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    ll n,ans=0;
    cin >> n;
    vector<ll> data(n);
    vector<ll> dp(n+1,0);
    dp.at(0)=0;
    rep(i,n){
        cin >> data.at(i);
    }
    rep(i,n+1){
        if(i==0) continue;
        dp.at(i)=dp.at(i-1)+data.at(i-1);
    }

    map<ll,ll> cnt;
    for(ll i=0; i<=n; i++){
        cnt[dp.at(i)]++;
    }

    for(auto it : cnt){
        ll num=it.second;
        ans+=num*(num-1)/2;
    }

    cout << ans << endl;
    
    
 
}