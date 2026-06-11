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
    lint N, C; cin >> N >> C;

    vector<P> sushi;
    REP(_, N) {
      lint x, v; cin >> x >> v;
      sushi.push_back(P(x, v));
    }
    vector<P> forward;
    lint forward_max = sushi[0].second - sushi[0].first;
    forward.push_back(P(forward_max, forward_max));
    
    FOR(i, 1, N) {
      lint sum = forward[i-1].first + sushi[i].second - sushi[i].first + sushi[i-1].first;

      if(sum >= forward_max) {
        forward_max = sum;
      }
      forward.push_back(P(sum, forward_max));
    }

    vector<P> rev;
    lint rev_max = sushi[N-1].second - (C-sushi[N-1].first);
    rev.push_back(P(rev_max, rev_max));
    
    FOR(i, 1, N) {
      lint sum = rev[i-1].first + sushi[N-1-i].second - (C-sushi[N-1-i].first) + (C-sushi[N-i].first);

      if(sum >= rev_max) {
        rev_max = sum;
      }
      rev.push_back(P(sum, rev_max));
    }

    lint res = 0;
    res = max(res, forward_max);
    res = max(res, rev_max);

    REP(i, N-1) {
      lint tmp = forward[i].first;
      tmp -= sushi[i].first;
      tmp += rev[N-2-i].second;
      
      res = max(res, tmp);
    }

    REP(i, N-1) {
      lint tmp = rev[i].first;
      tmp -= C-sushi[N-1-i].first;
      tmp += forward[N-2-i].second;
      res = max(res, tmp);
    }
    
    
    cout << res << "\n";

    return 0;
}
