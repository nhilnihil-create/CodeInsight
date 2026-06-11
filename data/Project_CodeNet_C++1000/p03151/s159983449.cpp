#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll n,p; cin>>n;
ll a[n]={};
ll b[n]={};
ll ca=0;
ll cb=0;
ll w=0;
rep(i,n){
cin>>a[i];
ca+=a[i];}
rep(i,n){
cin>>b[i];
cb+=b[i];}
if(ca<cb){
cout << -1 << endl;}
else{
ca=0;
cb=0;
rep(i,n){
if(a[i]<b[i]){
ca+=b[i]-a[i];
w++;}}
ll c[n]={};
ll q=0;
rep(i,n){
if(a[i]>b[i]){
c[q]=a[i]-b[i];
q++;}}
sort(c,c+n);
reverse(c,c+n);
q=0;
cb=0;
while(ca>cb){
cb+=c[q];
q++;}
cout << q+w << endl;}}
