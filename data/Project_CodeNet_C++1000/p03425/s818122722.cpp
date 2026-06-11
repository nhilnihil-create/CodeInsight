#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

vector<vector<ll>> totComb;
vector<int> people = {1, 2, 3, 4, 5};
vector<ll> ct(6, 0);
vector<ll> combination;

void go(int offset, int k) {
if (k == 0) {
    totComb.push_back(combination);
    return;
  }

  for (int i = offset; i <= people.size() - k; ++i) {
    combination.push_back(people[i]);
    go(i+1, k-1);
    combination.pop_back();
  }
}


int main(){
    ll n;
    cin >> n;

    vector<string> s(n, "");
    REP(i, n) {
        cin >> s[i];
        if (s[i][0] == 'M') ct[1]++;
        if (s[i][0] == 'A') ct[2]++;
        if (s[i][0] == 'R') ct[3]++;
        if (s[i][0] == 'C') ct[4]++;
        if (s[i][0] == 'H') ct[5]++;
    }

    go(0, 3);

    ll ans = 0;

    REP(i, totComb.size()){
        ll curr = 1;
        REP(j, totComb[i].size()){
            curr *= ct[totComb[i][j]];
        }
        ans += curr;
    }

    cout << ans << endl;

}
        
