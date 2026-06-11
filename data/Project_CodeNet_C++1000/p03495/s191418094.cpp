#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K, d; cin >> N >> K;
	unordered_map <int, int> mp;
	for (int i = 0; i < N; ++i){
		cin >> d;
		++mp[d];
	}
//	assert(m.size() == N);
	set <pair<int,int>> s;
	for (auto it = mp.begin(); it != mp.end(); ++it){
//		cout << *it << " " << m.count(*it) << "\n";
		s.insert(make_pair(it->second, it->first));
	}
//j	cout << s.size() << "\n";
	
	int cnt = 0;
	while (s.size() > K){
//		if (s.size() - *s.begin().first > K){
			cnt += s.begin()->first;	
			s.erase(s.begin());		
	}
	cout << cnt << "\n";	
	return 0;
}
