#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll go(vector<pair<int,int> >a, bool f){
	multiset<pair<int,int> >l, r;
	for(int i = 0; i < a.size(); i++)
		l.insert(a[i]), r.insert({a[i].second, a[i].first});
	ll ret = 0, cur = 0;
	while(l.size()){
		pair<int,int> tmp;
		if(f){
			tmp = *r.begin();
			r.erase(r.begin());
			l.erase(l.find({tmp.second, tmp.first}));
		}
		else{
			tmp = *l.rbegin();
			l.erase(--l.end());
			r.erase(r.find({tmp.second, tmp.first}));
		}
		f = !f;
		if(cur >= tmp.first && cur <= tmp.second ||
				cur <= tmp.first && cur >= tmp.second)
			continue;
		if(abs(cur - tmp.first) > abs(cur - tmp.second))
			swap(tmp.first, tmp.second);
		ret += abs(cur - tmp.first);
		cur = tmp.first;
		//		cerr << cur << endl;
	}

	return ret + abs(cur);
}

int main() {
	ios::sync_with_stdio(false);
	//	srand(time(NULL));
	int n; cin >> n;
	vector<pair<int,int> >a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	cout << max(go(a, 0), go(a, 1)) << endl;
	return 0;
}
