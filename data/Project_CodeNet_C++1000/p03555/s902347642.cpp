#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  string s1, s2;
  cin >> s1;
  cin >> s2;

  if((s1[0] == s2[2]) && (s1[1] == s2[1]) && (s1[2] == s2[0]))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}
