#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFF 9223372036854775807
#define ll long long
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,m,n) for(int i=m;i<n;i++)
#define ALL(N) (N.begin(),N.end())

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int count=0;
  string s;
  cin >> s;
  REP(i,s.size()) {
    if(s[i]=='x') count++;
  }
  if(count<8) cout << "YES" << endl;
  else cout << "NO" << endl;
}