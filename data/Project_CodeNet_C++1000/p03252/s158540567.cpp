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
const double pi=acos(-1);
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
//cout << fixed << setprecision(12);
string s,t;
cin>>s>>t;
ll ca=0;
ll cb=0;
ll n = s.size();
ll a[n]={};
ll b[30]={};
char q;
rep(i,n){
ll k = t.at(i)-'a';
//cout << k << endl;
a[i]=k;}
//rep(i,n){
//cout << a[i] << endl;}
rep(i,30){
rep(j,n){
//cout << "i " << i << endl;
if(a[j]==i&&ca==0){
ca++;
q = s.at(j);
//cout << q << endl;
continue;}
if((a[j]==i&&s.at(j)!=q)||(a[j]!=i&&s.at(j)==q)){
cb++;
//cout << i << " " << j << endl;
goto asd;}
}
ca=0;
q ='6';
}
asd:
if(cb>0){
cout << "No" << endl;}
else{
cout << "Yes" << endl;}}
