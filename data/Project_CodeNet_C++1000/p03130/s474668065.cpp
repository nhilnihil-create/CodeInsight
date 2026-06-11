#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<pair<int,int>> f(3);
 	for (auto& x : f) cin >> x.first >> x.second;
    for (int x=0;x<8;++x) {
      auto e = f;
      for (int i = 0; i < 3; ++i) {
       	if ((x>>i)&1) swap(e[i].first, e[i].second); 
      }
     sort(e.begin(), e.end());
	do {
    	if (e[0].second == e[1].first && e[1].second == e[2].first && e[0].first != e[2].second) {
          cout << "YES\n";
          return 0;
        }
    } while (next_permutation(e.begin(), e.end()) ); 
      
    }
    cout << "NO\n";
}
