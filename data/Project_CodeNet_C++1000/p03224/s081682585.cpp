#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
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
    lint k = 2;

    while(true) {
      if(k*(k-1) == 2*N) {
        break;
      }

      if(k == N) {
        cout << "No\n";
        return 0;
      }

      k++;
    }

    lint size = k-1;

    vector<vector<lint>> S;

    REP(_, k) {
      vector<lint> s;
      S.push_back(s);
    }


    lint idx = 1;
    FOR(i,0,k) {
      FOR(j,i+1,k) {
        S[i].push_back(idx);
        S[j].push_back(idx);
        idx++;
      }
    }

    PRINT("Yes");
    PRINT(k);

    REP(i,k) {
      cout << size; cout << " "; EACHPRINT(S[i], lint);
    }
    
    return 0;
}
