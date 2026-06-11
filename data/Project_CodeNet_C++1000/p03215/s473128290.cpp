#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<ll> sum;
    for(int i=0;i<n;i++){
        ll tmp=0;
        for(int j=i;j<n;j++){
            tmp+=a[j];
            sum.push_back(tmp);
        }
    }
    sort(ALL(sum),greater<ll>());
    //debug(sum);
    ll tmp=sum[0];
    ll keta=0;
    while(tmp>0){
        tmp>>=1;
        keta++;
    }

    // cout<<keta<<endl;
    // cout<<((1<<(keta-1))&sum[0])<<endl;

    //最上位桁の確定
    ll shif=keta-1;
    bool f=false;
    vector<ll> v;
    for(ll i=shif;i>=0;i--){
        for(int j=0;j<sum.size();j++){
            if((1)&(sum[j]>>i)) v.push_back(sum[j]);
        }
        if(!f&&v.size()>=k){
            break;
        }
        else{
            v.clear();
        }
    }
    sort(ALL(v),greater<ll>());
    //debug(v);
    keta=0;
    tmp=v[0];
    while(tmp>0){
        keta++;
        tmp>>=1;
    }
    keta--;
    for(ll i=keta;i>=0;i--){
        vector<ll> v2;
        for(int j=0;j<v.size();j++){
            if((1)&(v[j]>>i)){
                v2.push_back(v[j]);
            }
        }
        if(v2.size()>=k){
            swap(v,v2);
        }
        //debug(v);
    }
    sort(ALL(v),greater<ll>());
    ll ans=v[0];
    for(int i=1;i<k;i++){
        ans&=v[i];
    }
    cout<<ans<<endl;
    return 0;
}
