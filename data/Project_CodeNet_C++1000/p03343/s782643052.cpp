#pragma GCC optimize("O3")
#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    V<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    multiset<ll> s;
    V<ll> tmp;
    ll ans=inf;
    for(int i=0;i<n;i++){
        s.clear();
        tmp.clear();
        for(int j=0;j<n;j++){
            if(a[j]>=a[i]){
                s.insert(a[j]);
                if(s.size()==k){
                    tmp.emplace_back(*s.begin());
                    s.erase(s.begin());
                }
            }else{
                s.clear();
            }
        }
        if(tmp.size()>=q){
            sort(all(tmp));
            chmin(ans,tmp[q-1]-a[i]);
        }
    }
    cout<<ans<<"\n";
}