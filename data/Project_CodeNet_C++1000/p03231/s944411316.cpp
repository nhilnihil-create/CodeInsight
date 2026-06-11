#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int ll

ll gcd(ll m, ll n) {//最大公約数
    if (n == 0)return m;
    return gcd(n, m % n);
}//gcd

ll lcm(ll m, ll n) {//最小公倍数
    return m / gcd(m, n) * n;
}

main(){
  int n,m;
  cin>>n>>m;
  string s,t;
  cin>>s>>t;
  int l = lcm(n,m);
  map<int,char> mp_n,mp_m;
  for(int i = 0; i <= n - 1; i++){
    mp_n[l/n*i]=s[i];
  }
  for(int i = 0; i <= m - 1; i++){ 
    mp_m[l/m*i]=t[i];
  }
  bool ok=1;
  for(auto x : mp_n){
    if(x.second != mp_m[x.first] && ('a'<=mp_m[x.first] && mp_m[x.first]<='z') ) ok=0;
  }
  if(ok) cout<<l<<endl;
  else cout<<-1<<endl;
}

