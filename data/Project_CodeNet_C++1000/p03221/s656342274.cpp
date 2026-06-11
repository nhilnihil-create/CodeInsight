#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){

  int n,m;cin>>n>>m;
  vector<vector<pair<ll,int>>> p(100005);
  string num[100002];
  rep(i,m){
    int x;ll y;
    cin>>x>>y;

    p[x].emplace_back(make_pair(y,i+1));
  }

  for (int i = 1; i <= n; i++)
  {
    if(p[i].empty())continue;
    sort(p[i].begin(),p[i].end());
    rep(j,p[i].size()){
      string pn,xn;
      pn = to_string(i);
      xn = to_string(j+1);
      int n0f,n0b;
      n0f = 6-pn.length();n0b = 6-xn.length();
      rep(k,n0f)num[p[i][j].second] += '0';
      num[p[i][j].second] += pn;
      rep(k,n0b)num[p[i][j].second] += '0';
      num[p[i][j].second] += xn;
    }
  }

  for (int i = 1; i <= m; i++){
    cout<<num[i]<<endl;
  }
  return 0;
}