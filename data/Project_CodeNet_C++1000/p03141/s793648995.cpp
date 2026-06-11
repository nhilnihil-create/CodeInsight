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
ll k=0;
ll c[n]={};
rep(i,n){
cin>>a[i]>>b[i];
cb+=b[i];
c[i]=a[i]+b[i];}
sort(c,c+n);
if(n%2==0){
rep(i,n){
if(i%2==0){
k++;}
else{
ca+=c[i];}
}}
else{
rep(i,n){
if(i%2==0){
ca+=c[i];
}
else{
k++;
}
}}
ll ans = ca - cb;
cout << ans << endl;}
