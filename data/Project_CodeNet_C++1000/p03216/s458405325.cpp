#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,k,n) for(ll i=(ll)(k);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int mod=1e9+7;
const ll inf=1001001001001001;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}

int main(){
    ll n;cin>>n;
    string s;cin>>s;
    ll q;cin>>q;
    rep(i,q){
        ll k,ans=0,sum=0,d=0,m=0;cin>>k;
        rep(i,n){
            if(s[i]=='D')d++;
            if(s[i]=='M'){
                sum+=d;
                m++;
            }
            if(i-k>=0){
                if(s[i-k]=='D'){
                    sum-=m;
                    d--;
                }
                if(s[i-k]=='M')m--;
            }
            if(s[i]=='C')ans+=sum;
        }
        out(ans);
    }
}