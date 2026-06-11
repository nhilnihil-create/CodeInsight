#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

ll GCM(ll a,ll b){
  ll r = a%b;
  while(r!=0){
    a = b;
    b = r;
    r = a%b;
  }

  return b;
}

int main(){
  ll n,m; cin >> n >> m;
  string s1,s2; cin >> s1 >> s2;

  ll gcd = GCM(max(n,m),min(n,m)); /*最小公倍数*/
  ll lcm = n*m/gcd;
  ll a = n/gcd,b = m/gcd;

  bool ok = true;
  for(int i=0;i<gcd;i++){
    if(s1.at(a*i)!=s2.at(b*i)) ok = false;
  }

  if(ok) cout << lcm << endl;
  else puts("-1");
}
