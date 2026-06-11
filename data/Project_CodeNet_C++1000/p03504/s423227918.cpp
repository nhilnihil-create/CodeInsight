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
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll imos[31][100005];
int main(){
    int n,ch;
    cin>>n>>ch;
  for(int i=0;i<n;i++){
      int a,b,c;
      cin>>a>>b>>c;
      imos[c-1][a-1]++;
      imos[c-1][b]--;
  }
  for(int i=0;i<ch;i++){
       for(int j=0;j<100001;j++)imos[i][j+1]+=imos[i][j];
  }
   for(int i=0;i<100001;i++){
       for(int j=0;j<ch;j++)imos[j+1][i]+=min((ll)j+1,imos[j][i]);
  }
ll ans=0;
 for(int i=0;i<100001;i++){
     chmax(ans,imos[ch][i]);
 }
 cout<<ans<<endl;
}
