#include <bits/stdc++.h>
#define rep(i,x,n) for(int i = x; i < (int)(n); i++)
#define rep_ll(i,x,n) for(ll i = x; i < (ll)(n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
const long double PI = (acos(-1));
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0}; const int dy[] = {0, -1, 0, 1};
ll mod = 1000000007;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    /*vector<int> s(n+1, 0);
    s[0]=0;
    rep(i, 1, n+1) s[i]=s[i-1]+a[i-1];
    int ans=0;
    rep(i, 0, n+1) rep(j, i+1, n+1)if(s[j]-s[i]==0) ans++;*/
    vector<ll> s(n+1,0);
    //部分和はsi-sjで表すsi-sj=0⇒si=sjとなるものを探す
    map<ll, ll> nums;
    rep(i, 0, n) s[i+1]=s[i]+a[i];
    rep(i, 0, n+1) nums[s[i]]++;//和がs[i]になる配列が何個あるか
    ll ans=0;
    for(auto it: nums){
        ll num = it.second;
        ans+=num*(num-1)/2;//numC2
    }
    cout << ans;
    return 0;
}