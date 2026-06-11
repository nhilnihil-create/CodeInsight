#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main() {
  int a,b; cin >> a >> b;
  string s; cin >> s;
  bool ans = true;
  rep(i,s.size()){
    if (i < a && s[i] == '-')ans = false;
    if (i == a && s[i] != '-') ans = false;
    if (i > a && s[i] == '-') ans = false;
  }

  cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

