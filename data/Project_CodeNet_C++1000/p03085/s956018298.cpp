#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;

int main(){
  string s; cin >> s;
  map<string, string> m;
  m["A"]="T";
  m["C"]="G";
  m["G"]="C";
  m["T"]="A";
  cout << m[s];
  return 0;
}
