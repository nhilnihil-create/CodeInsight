#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int h,w,n;
cin>>h>>w>>n;
int nx,ny;
cin>>nx>>ny;
nx--;ny--;
string s,t;
cin>>s>>t;
bool stay=true;
int l=0,r=w-1;
if(s[n-1]=='L')l++;
if(s[n-1]=='R')r--;
//左右
for(int i=n-2;i>=0;i--){
    if(t[i]=='L'&&r!=w-1)r++;
    if(t[i]=='R'&&l!=0)l--;
    if(s[i]=='L')l++;
    if(s[i]=='R')r--;
    if(l>r)stay=false;
}
 if(ny<l||ny>r)stay=false;
int u=0,d=h-1;
if(s[n-1]=='U')u++;
if(s[n-1]=='D')d--;
//上下
for(int i=n-2;i>=0;i--){
    if(t[i]=='U'&&d!=h-1)d++;
    if(t[i]=='D'&&u!=0)u--;
    if(s[i]=='U')u++;
    if(s[i]=='D')d--;
    if(u>d)stay=false;
}
if(nx<u||nx>d)stay=false;
if(stay)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}