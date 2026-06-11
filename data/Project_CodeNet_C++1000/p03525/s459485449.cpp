//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int n;
	cin >> n;
	map<int, int> mp;
	REP(i,n){
		cin >> tmp;
		mp[tmp]++;
	}
	vector<int> v;
	int only = 0;
	bool zero = false;
	for(auto it = mp.begin(); it != mp.end(); it ++){
		if(it->second >= 3) zero = true;
		if(it->second == 2){
			v.push_back(-12 + it->first);
			v.push_back(12 - it->first);
		}
		if(it->second == 1) only += 1 << it->first;
	}
	vector<int> now;
	ans = 0;
	REP(i, 1 << 13){
		now.clear();
		now.push_back(-12);
		now.push_back(12);
		copy(v.begin(), v.end(), back_inserter(now));
		REP(j, 13){
			if(only & (1<<j)){
				if(i & (1<<j)) now.push_back(-12 + j);
				else now.push_back(12 - j);
			}
		}
		sort(now.begin(), now.end());
		tmp = 24;
		REP(i, now.size()-1) tmp = min(tmp, now[i+1] - now[i]);
		ans = max(ans, tmp);
	}
	if(zero) cout << 0 << endl;
	else cout << ans << endl;
}