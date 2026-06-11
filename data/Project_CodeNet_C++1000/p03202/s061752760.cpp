    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <bitset>
    #include <set>
    #include <map>
    #include <string>
    #include <cmath>
    #include <ctime>
    #include <queue>
     
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    #define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
     
    const ll SIZE = 1000, INF = 1e9 * 1e9, MOD = 1e9 + 7;
     
    vector<ll> vec;
     
    bool check(int m) {
    	vector<pair<ll, ll>> s;
    	s.push_back({ 0, 0 });
     
    	for (int i = 1; i < vec.size(); i++) {
    		if (vec[i] > vec[i - 1]) {
    			continue;
    		}
    		else {
    			while (s.back().first > vec[i]) s.pop_back();
     
    			if (s.back().first < vec[i]) {
    				s.push_back({ vec[i], 2 });
    				if (m == 1) return false;
    				continue;
    			}
    			if (s.back().first == vec[i]) {
    				ll pr = vec[i];
    				while (s.size() >= 1 && s.back().second == m && s.back().first == pr) {
    					s.pop_back();
    					pr--;
    				}
    				if (pr <= 0) return false;
    				if (s.back().first == pr) s.back().second++;
    				else {
    					if (m == 1) return false;
    					s.push_back({ pr, 2 });
    				}
    			}
    		}
    	}
    	return true;
    }
     
    signed main() {
    	fastInp;
     
    	ll n;
    	cin >> n;
    	vec.resize(n);
    	for (int i = 0; i < n; i++) cin >> vec[i];
     
    	ll l = 0, r = 2e5;
    	while (r - l > 1) {
    		ll mid = (l + r) / 2;
    		if (check(mid)) {
    			r = mid;
    		}
    		else {
    			l = mid;
    		}
    	}
    	
    	cout << r;
    	return 0;
    }