#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  string s;cin>>s;
  int k;cin>>k;
  k=min(100,k);
  rep(i,k){
    if(s[i]!='1') {cout<<s[i];return 0;}
  }
  cout<<'1';
  return 0;
}