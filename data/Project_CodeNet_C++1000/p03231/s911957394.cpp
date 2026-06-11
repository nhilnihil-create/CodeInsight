#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  ll n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  int g = __gcd(n,m);
  bool check = true;
  rep(i,g){
    if (s[i*n/g]!=t[i*m/g]) check = false;
  }
  cout << (check? n*m/g : -1) << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}

