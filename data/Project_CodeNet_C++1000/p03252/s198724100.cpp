#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  string s,t;
  cin>>s>>t;
  bool ans=true;
  string alpha="abcdefghijklmnopqrstuvwxyz";
  string al="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  rep(i,26){
      rep(j,sz(s)){
          if(s[j]==alpha[i]){
              al[i]=t[j];
              break;
          }
      }
  }
  rep(i,25){
      for(ll j=i+1;j<26;j++){
          if(al[i]==al[j]){
              ans=false;
          }
      }
  }
  rep(i,26){
      rep(j,sz(s)){
          if(s[j]==alpha[i]&&t[j]!=al[i]){
              ans=false;
              i=30;
              break;
          }
      }
  }
  cout<<(ans?"Yes":"No")<<endl;
}
