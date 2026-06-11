#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009

ll gcm(ll a,ll b){
  if(a < b) swap(a,b);
  if(b == 0) return a;
  return gcm(a%b,b);
}

ll lcm(ll a,ll b){
  return a*b/gcm(a,b);
}

int main(){
  ll n,m;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;
  ll nm = lcm(m,n);
  ll muln = nm / n;
  ll mulm = nm / m;
  int nown = 0;
  int nowm = 0;
  bool flag = true;
  while(nown < n && nowm < m){
    //cout << s[nown] << " " << t[nowm] << endl;
    if(s[nown] != t[nowm]){
      flag = false;
    }
    nown += mulm;
    nowm += muln;
    //cout << flag << endl;
  }
  if(flag) cout << nm << endl;
  else cout << -1 << endl;
}
