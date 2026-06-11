#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <bitset>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=s;i<t;i++)
#define REP(i,n) FOR(i,0,n)
#define LAST(i,n) if(i==n-1)
#define PRINT(s) cout << s << "\n"
#define SORT(A) sort(A.begin(), A.end())
#define EACHPRINT(A, T) for_each(begin(A), end(A), [&](T i){ cout << i << " "; });cout << "\n"

typedef long lint;
typedef pair<lint, lint> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    lint N; cin >> N;

    vector<lint> A;
    FOR(_, 0, pow(2,N)) {
      lint a; cin >> a; A.push_back(a);
    }

    lint res = 0;
    vector<P> maxpair;
    maxpair.push_back(P(-1,-1));

    FOR(K, 1, pow(2, N)) {
      P p;
      if(!(K&(K-1))) {
        p=P(0, K);
      }
      else {
        set<lint> s;
        s.insert(K);

        REP(i, N) {
          lint mask = 1 << i;
          if ((K & mask) == mask) {
            lint masked = K & ~mask;

            s.insert(maxpair[masked].first);
            s.insert(maxpair[masked].second);
          }
        }
    
        lint first = -1;
        lint second = -1;
        for(set<lint>::iterator it = s.begin();
            it != s.end();
            ++it){
          if (first == -1 || A[*it] >= A[first]) {
            if(first != -1) {
              second = first;
            }
            first = *it;
          }
          else if(second == -1 || A[*it] >= A[second]) {
            second = *it;
          }
        }
        p = P(first, second);
      }

      //            cout << "K "<< K << " " <<  p.first << " -> " << A[p.first] << " " << p.second << " -> " << A[p.second] << "\n";

      maxpair.push_back(p);
      res = max(res, A[p.first] + A[p.second]);
      PRINT(res);
    }

    return 0;
}
