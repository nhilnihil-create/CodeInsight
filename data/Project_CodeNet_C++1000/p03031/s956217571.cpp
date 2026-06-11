#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int ans = 0;
  int n, m;
  cin >> n >> m;
  int k[m];
  vector<vector<int>> s(m);
  vector<int> p(m);
  REP(i,0,m){
    cin >> k[i];
    s[i].resize(k[i]);
    REP(j,0,k[i]){
      cin >> s[i][j];
      s[i][j]--;
    }
  }
  REP(i,0,m){
    cin >> p[i];
  }

  for (int i = 0; i < (1 << n); ++i) {
		bool ok = true;
		REP(j,0,m) {
			int c = 0;
			for (int id : s[j]) {
				if ((i >> id) & 1) {
					++c;
				}
			}
			c %= 2;
			if (c != p[j]) {
				ok = false;
			}
		}
		if (ok) {
			++ans;
		}
	}

  cout << ans << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}