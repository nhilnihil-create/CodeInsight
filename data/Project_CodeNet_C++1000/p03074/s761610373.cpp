#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=110000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x, ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  ll n,k;
  string s;
  cin >> n >> k >> s;
  vector<int>num;
  if(s[0]=='0')num.push_back(0);
  for(int i=0;i<n;){
    int j=i;
    while(j<n && s[j]==s[i])j++;
    num.push_back(j-i);
    i=j;
  }
  vector<int>sum(num.size()+1,0);
  rep(i,num.size()){
    sum[i+1]=sum[i]+num[i];
  }
  int ans=0;
  for(int l=0;l<sum.size();l+=2){
    int r=l+k*2+1;
    if(r>=sum.size())r=sum.size()-1;
    chmax(ans,sum[r]-sum[l]);
  }
  cout << ans << endl;
    
  
}