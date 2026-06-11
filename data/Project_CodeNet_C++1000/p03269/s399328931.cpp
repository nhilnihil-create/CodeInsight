#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v;

    int x, n = 20;
    cin >> x;

    for (int i = 0; i < n - 1; i++) {
    	v.push_back({i, i + 1, 0});
    }

    vector<int> anime;

    while (x > 0) {
    	for (int i = 0; ; i++) {
    		if ((x >> i) & 1) {
    			anime.push_back(i);
    			x ^= (1 << i);
    			break;
    		}
    	}
    }

    reverse(all(anime));

    for (int i = n - 1 - anime[0]; i + 1 < n; i++) {
    	v.push_back({i, i + 1, 1 << (n - 2 - i)});
    }

    int pref = 1 << anime[0];
    anime.erase(anime.begin());

    for (int x : anime) {
    	if ((n - 1 - x) != 0) {
    		v.push_back({0, n - 1 - x, pref});
    	}
    	pref |= 1 << x;
    }

    cout << n << " " << v.size() << "\n";
    for (auto e : v) {
    	cout << e[0] + 1 << " " << e[1] + 1 << " " << e[2] << "\n";
    }

    return 0;   
}