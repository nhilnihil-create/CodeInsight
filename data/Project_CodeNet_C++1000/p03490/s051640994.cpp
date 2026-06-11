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
bitset<16005> dpx[16005],dpy[16005];
ll mid=8000;
int main(){
string s;
cin>>s;
int x,y;
cin>>x>>y;
dpx[0][mid]=1;dpy[0][mid]=1;
int n=s.size();
int j=1;
int t=0,cnt=0;
for(int i=0;i<n;){
    if(t%2==0){
        while(i<n&&s[i]!='T'){
            i++;
            cnt++;
        }
        if(j==1){
            dpx[j]|=(dpx[0]<<cnt);
        }
        else{
            dpx[j]|=(dpx[j-1]<<cnt);
            dpx[j]|=(dpx[j-1]>>cnt);
        }
        cnt=0;
        j++;
    }
    if(s[i]=='T'){
    while(i<n&&s[i]=='T'){
        i++;
        t++;
    }
    }
    else i++;
}
int k=1;
t=0;
for(int i=0;i<n;){
    if(t%2==1){
        while(i<n&&s[i]!='T'){
            i++;
            cnt++;
        }
         dpy[k]|=(dpy[k-1]<<cnt);
         dpy[k]|=(dpy[k-1]>>cnt);
        k++;
        cnt=0;
    }
   if(s[i]=='T'){
    while(i<n&&s[i]=='T'){
        i++;
        t++;
    }
    }
    else i++;
}
if(dpx[j-1][x+mid]&&dpy[k-1][y+mid])cout<<"Yes"<<"\n";
else cout<<"No"<<"\n";
}