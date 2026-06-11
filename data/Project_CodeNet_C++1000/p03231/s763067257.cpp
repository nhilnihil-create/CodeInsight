//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>>vvi;
typedef pair<int,int> P;
int main(){
  ll n,m;
  string s,t;
  cin>>n>>m>>s>>t;
  ll l=n/__gcd(n,m)*m;
  ll b=l/n;
  ll a=l/m;
  bool ans=true;
  int j=0;
  for(int i=0;i<n;i+=a){
    if(s[i]!=t[j]){
      ans=false;
    }
      j+=b;
    
  }
  if(ans)cout<<l<<endl;
  else cout<<-1<<endl;
}
      