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
  int n;cin>>n;
  vector<int> c(n),s(n),f(n);
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
  int now = n-2;
  ll time[n];time[n-1] = 0;
  rep(i,n-1){
    ll t = s[i] + c[i];
    for (int j = i+1; j < n-1; j++)
    {
      if(t<=s[j])t = s[j] +c[j];
      else {
        if((t-s[j])%f[j]==0)t += c[j];
        else t = ((t-s[j])/f[j]+1)*f[j]+c[j]+s[j];
      }
    }
    time[i] = t;
  }

  rep(i,n)cout<<time[i]<<endl;
  return 0;
}