# include <bits/stdc++.h>
# define rep(i,n) for (int i = 0; i < (n); ++i)
# define FI first
# define SE second
using namespace std;
using P = pair<string, int>;

int main() {
  int n; cin >> n;
  vector<P> towns(n);
  map<int, int> mp;
  rep (i, n) {
    string s; int p; cin >> s; cin >> p;
    towns[i].FI = s;
    towns[i].SE = p;
    mp[p] = i + 1;
  }
  
  sort(towns.begin(), towns.end(), [](P a, P b) {
    if(a.FI != b.FI){
        return a.FI < b.FI;
    } else {
        return a.SE > b.SE;
    }
  });
  
  rep (i, n) {
  	cout << mp[towns[i].SE] << endl;
  }
  
  return 0;
}
