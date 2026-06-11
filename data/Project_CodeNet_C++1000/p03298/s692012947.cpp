#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<string,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    map<pair<string,ll>,ll> mp1,mp2;
    for(ll i=0;i<(1<<n);i++){
        string x,y,z,w;
        ll cnt=0;
        for(ll j=0;j<n;j++){
            if(i>>j&1){
                x+=s[j];
                z+=s[j+n];
                cnt++;
            }else{
                y+=s[j];
                w+=s[j+n];
            }
        }
        reverse(all(y));
        x+=y;
        reverse(all(w));
        w+=z;
        mp1[make_pair(x,cnt)]++;
        mp2[make_pair(w,cnt)]++;
    }
    for(auto p:mp1){
        ans+=p.sc*mp2[make_pair(p.ft.ft,n-p.ft.sc)];
    }
    cout<<ans<<endl;
}