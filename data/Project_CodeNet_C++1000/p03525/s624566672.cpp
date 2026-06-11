#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
int n;cin>>n;
V<int> a(n);
for(int i=0;i<n;i++)cin>>a[i];
if(n>24){
    cout<<0<<endl;
    return 0;
}
 if(n>13){
    V<int> cnt(n);
    cnt[0]++;
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        if(cnt[0]==2||cnt[a[i]]==3){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
    return 0;
}
int ans=0;
for(int bit=0;bit<(1<<n);bit++){
    V<int> d(n+1);
    for(int i=0;i<n;i++){
        if(a[i]==0||bit&(1<<i))d[i]=a[i];
        else d[i]=24-a[i];
    }
    d[n]=0;
    int res=INT_MAX;
    for(int i=0;i<n+1;i++){
        for(int j=i+1;j<n+1;j++){
            int t=abs(d[i]-d[j]);
            if(t>12)t=24-t;//(ex)0,13の時時差は１３時間でない　(時差の最大値は12であるため) 
              chmin(res,t);
        }
    }
    chmax(ans,res);
}
cout<<ans<<endl;
}
