#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, C, s, t, c; cin >> N >> C;
	vector <vector <pair<int,int>>> v(C);
	for (int i = 0; i < N; ++i){
		cin >> s >> t >> c;
		s *= 2; t *= 2; --c;
		v[c].emplace_back(s,t);
	}
	vector <int> ava(2e5 + 2), ava2(2e5+2);
	for (int i = 0; i < C; ++i){
		if (!v[i].empty()){
		sort(v[i].begin(),v[i].end());
		++ava[v[i][0].first-1];
		for (int j = 1; j < v[i].size(); ++j){
			if (v[i][j-1].second != v[i][j].first){
				--ava[v[i][j-1].second];
				++ava[v[i][j].first-1];
			}
		}
		--ava[v[i][v[i].size()-1].second];
		for (int i = 1; i < ava.size(); ++i){
			ava[i] += ava[i-1];
		}	
		for (int i = 0; i < ava2.size(); ++i){
			if (ava[i] > 0) ++ava2[i];
		}
		ava.clear();
		ava.resize(2e5 + 2);
		}
	}
	cout << *max_element(ava2.begin(),ava2.end()) << "\n";
	/*
	vector <pair<int,int>> sor;
	for (int i = 0; i < C; ++i){
		sort(v[i].begin(),v[i].end());
		vector <pair<int,int>> tmp;
		if (!v[i].empty()){
//			pair<int,int> p;
			int x = v[i][0].first;
			for (int j = 1; j < v[i].size(); ++j){
				if (v[i][j-1].second != v[i][j].first){
					tmp.emplace_back(x, v[i][j-1].second);
					x = v[i][j].first;
				}
			}
			tmp.emplace_back(x, v[i][v[i].size()-1].second);	
		}
//		cout << "Test " << i  << " " << tmp.size()<< "\n";
		for (auto i : tmp){
			sor.push_back(i);
		}	
	}
	sort(sor.begin(),sor.end());
//	for (auto i : sor){
//		cout << i.first <<  " " << i.second << "\n";
//	}
	int req = 1;
	multiset <int> free;
	for (int i = 0; i < sor.size(); ++i){
		if (free.empty()){
			free.insert(sor[i].second);
		}else{
			if (*free.begin() < sor[i].first){
				free.erase(free.begin());
				free.insert(sor[i].second);
			}else{
				++req;
				free.insert(sor[i].second);
			}
		}
	}
	cout << req << "\n";
*/	
	return 0;
}
