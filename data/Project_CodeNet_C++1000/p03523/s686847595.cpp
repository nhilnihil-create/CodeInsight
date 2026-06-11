#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  string S; cin >>S;
  bool a=regex_match(S,regex("A?KIHA?BA?RA?"));
  cout <<(a ? "YES":"NO") <<endl;
  return 0;
}
