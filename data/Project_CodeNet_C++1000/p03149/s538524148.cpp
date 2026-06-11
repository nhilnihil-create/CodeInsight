#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  vector<int> v;
  int n;
  REP(i, 4) {
    cin >> n;
    v.push_back(n);
  }

  sort(v.begin(), v.end());

  if (v[0] == 1 && v[1] == 4 && v[2] == 7 && v[3] == 9) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}