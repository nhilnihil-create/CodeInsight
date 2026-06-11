#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=s;i<t;i++)
#define REP(i,n) FOR(i,0,n)
#define PRINT(s) cout << s << "\n"
#define SORT(A) sort(A.begin(), A.end())
#define EACHPRINT(A, T) for_each(begin(A), end(A), [&](T i){ cout << i << " "; });cout << "\n"

typedef long lint;
typedef pair<lint, lint> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    lint N; cin >> N;

    vector<lint> a;

    REP(_, N) {
      lint x; cin >> x; a.push_back(x);
    }

    lint max_a = *max_element(a.begin(), a.end());

    lint res = 0;
    REP(i, N) {
      lint current_a = a[i];
      if( abs((max_a)/2 - current_a) < abs(max_a/2 - res)) {
        res = current_a;
      }
    }

    cout << max_a << " " << res << "\n";
    return 0;
}
