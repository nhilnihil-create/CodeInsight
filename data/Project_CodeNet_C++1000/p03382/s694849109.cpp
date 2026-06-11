#include <bits/stdc++.h>

#define mk make_pair
#define sc second
#define fr first
#define pb emplace_back
#define all(s) s.begin(), s.end()
#define sz(s) ( (int)s.size() )

using namespace std;

const int inf = (int)1e9 + 7;
const int N = (int)3e5 + 7;

int n;
int x;
vector <int> v;

main () {
      cin >> n;

      for (int i = 1; i <= n; i ++) {
            cin >> x;
            v.pb(x);
      }
      sort (v.begin(),v.end());

      for (int i = v.size() - 1; i >= 0; i --) {
            int x = (v[i] + 1) / 2;
            int pos = lower_bound(v.begin(),v.end(),x) - v.begin();
            if (pos != 0) {
                  if (v[pos - 1] == 0 || v[pos] == v[i])
                        continue;
                  if (x - v[pos - 1] > v[pos] - x) {
                        cout << v[i] << " " << v[pos] << endl;
                        return 0;
                  }
                  else {
                        cout << v[i] << " " << v[pos - 1] << endl;
                        return 0;
                  }
            }
            else {
                  if (v[pos] == 0 || v[pos] == v[i])
                        continue;
                  cout << v[i] << " " << v[pos] << endl;
                  return 0;
            }
      }
      cout << v[1] << " " << v[0] << endl;
}
