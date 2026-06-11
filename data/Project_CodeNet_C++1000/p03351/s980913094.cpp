#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
//const long long INF = 1LL << 60;

const int mod = 1e9 + 7;
const int INF = 100000;
int h,w;
int main() {
  int a,b,c,d;
  bool ok = false;
  cin >> a >> b >> c >> d;
  if(abs(a-c) <= d) ok = true;
  else if(abs(a-b) <= d && abs(b-c) <=d) ok = true;
  cout << (ok ? "Yes" : "No") << "\n";
}
