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
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    V<char> a(q),b(q);
    for(int i=0;i<q;i++)cin>>a[i]>>b[i];
    int l=-1,r=n;//rを場外用に開区間にしておく
    while(r-l>1){
        int mid=(l+r)/2;
        int now=mid;
        for(int i=0;i<q;i++){
            if(now<0||now>=n)break;
            if(s[now]!=a[i])continue;
            if(b[i]=='L')now--;
            else now++;
        }
        if(now<0)l=mid;
        else r=mid;
    }
    int L=r;
    l=-1,r=n;//lを場外用に開区間にしておく
     while(r-l>1){
        int mid=(l+r)/2;
        int now=mid;
        for(int i=0;i<q;i++){
            if(now<0||now>=n)break;
            if(s[now]!=a[i])continue;
            if(b[i]=='L')now--;
            else now++;
        }
        if(now>=n)r=mid;
        else l=mid;
    }
    cout<<max(0,l-L+1)<<"\n";
}