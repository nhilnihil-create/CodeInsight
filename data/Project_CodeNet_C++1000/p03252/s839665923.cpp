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
  string s,t;
  cin>>s>>t;
  int sz = s.length();
  int tz = t.length();
  if(tz!=sz){
    cout<<"No";
    return 0;
  }
  vector<int> als[26];
  rep(i,sz){
    int num = s[i]-'a';
    als[num].push_back(i);
  }

  rep(i,26){
  if(als[i].empty()) continue;
  char pre = t[als[i][0]]; 
  for(auto b: als[i]){
    if(t[b]!=pre){
      cout<<"No";
      //cout<<t[b]<<pre<<endl;
      return 0;
    }
  }
  }
  vector<int> als2[26];
  rep(i,sz){
    int num = t[i]-'a';
    als2[num].push_back(i);
  }

  rep(i,26){
  if(als2[i].empty()) continue;
  char pre = s[als2[i][0]]; 
  for(auto b: als2[i]){
    if(s[b]!=pre){
      cout<<"No";
      return 0;
    }
  }
  }
  cout<<"Yes";
  return 0;
}