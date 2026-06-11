#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
typedef tuple<ll,int,int> T;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,z,w; 
  cin>>n>>z>>w;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  if(n==1)cout<<abs(a[0]-w)<<endl;
  else cout<<max(abs(w-a[n-1]),abs(a[n-2]-a[n-1]))<<endl;
}