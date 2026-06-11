#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
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
string dp[10005];
int main(){
    V<ll> d={0,2,5,5,4,5,6,3,7,6};
    ll n,m;
    cin>>n>>m;
    V<int> a(n);
    for(int i=0;i<m;i++)cin>>a[i];
    sort(all(a),greater<ll>());
    for(int i=0;i<m;i++){
        for(int j=n;j>=d[a[i]];j--){
            if(j!=n&&dp[j].size()==0)continue;
             string t=dp[j];
            t.push_back(a[i]+'0');
             if(dp[j-d[a[i]]].size()<t.size())dp[j-d[a[i]]]=t;
            else if(dp[j-d[a[i]]].size()==t.size()){
                for(int k=0;k<t.size();k++){
                    if(dp[j-d[a[i]]][k]>t[k])break;
                    if(dp[j-d[a[i]]][k]<t[k]){
                        dp[j-d[a[i]]]=t;
                        break;
                    }
                }
           }
        }
    }
    cout<<dp[0]<<"\n";
}