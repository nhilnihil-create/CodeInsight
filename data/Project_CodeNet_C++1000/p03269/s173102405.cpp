#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll l;
    cin>>l;
    ll s=l,n=0,cnt=0;
    while(s>0){
        n++;
        if(s%2) cnt++;
        s/=2;
    }
    cout<<n<<" "<<2*(n-1)+cnt-1<<endl;
    rep2(i,1,n){
        cout<<i<<" "<<i+1<<" "<<0<<endl;
        cout<<i<<" "<<i+1<<" "<<(ll)pow(2,i-1)<<endl;
    }
    ll t=l-(ll)pow(2,n-1);
    ll now=(ll)pow(2,n-1);
    repr(bit,n+1){
        if(t>=(ll)pow(2,bit)){
            cout<<bit+1<<" "<<n<<" "<<now<<endl;
            now+=(ll)pow(2,bit);
            t-=(ll)pow(2,bit);
        }
    }
    return 0;
}