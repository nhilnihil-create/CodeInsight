#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	string s, t;
	cin >> s >> t;
	
	int sn = (int)s.size(); 
	int tn = (int)t.size();
	
	vector< pair<int, int> > p;
	bool match = true;
	
	for(int i = 0; i < sn; ++i) {
		int cnt = 0;
		match = true;
		
		for(int j = 0; j < tn; ++j) {
			if( s[i + cnt] == '?' || s[i + cnt] == t[j] ) {
				cnt++;
				continue;
			}
			
			if( s[i + cnt] != '?' && s[i + cnt] != t[j] ) {
				match = false; 
				break;
			}
		}
		
		if( match ) {
			p.push_back( {i, i + cnt} );
		}
	}
	
	vector<string> ans;
	
	if( (int)p.size() ) {
		for(int i = 0; i < (int)p.size(); ++i) {
			string tmp = "";
			int x = 0;
			
			for(int j = 0; j < sn; ++j) {
				if( j >= p[i].first && j < p[i].second ) {
					tmp += t[x];
					x++;
				} else {
					if( s[j] == '?' ) {
						tmp += 'a';
					} else {
						tmp += s[j];
					}
				}
			}
			
			ans.push_back(tmp);
		}
		
		sort(ans.begin(), ans.end());
		
		cout << ans.front();
		
	} else {
		cout << "UNRESTORABLE";
	}
	
	cout << endl;
	
	return 0;
}
