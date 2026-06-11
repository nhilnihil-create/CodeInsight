#include <bits/stdc++.h>
using namespace std;



int32_t main(){
	bool can = true;
	string s;
	cin >> s;
	int n = s.size();
	if(s[0] != '1') can = false;
	if(s[n-1] != '0') can = false;
	for(int i = 1 ; i < n-1; i ++){
		if(s[i] != s[n-i-2]) can = false;
	}
	if(!can){
		cout << -1 << endl;
	}
	else{
		set<int> p;
		vector<pair < int, int > > tree;
		int last = 1;
		int ac = 1;
		for(int i=1;i<n+1;i++) p.insert(i);
		p.erase(1);
		for(int i = 1 ; i < n; i ++){
			if(s[i] == '1'){
				int u = *p.begin();
				p.erase(u);
				tree.push_back({u,last});
				ac ++ ;
				last = u;
				while(ac != (i+1)){
					u = *p.begin();
					tree.push_back({u,last});
					p.erase(u);
					ac ++ ;
				}
			}
		}
		if(p.size()){
			tree.push_back({last, *p.begin()});
		}
		for(int i = 0 ; i < tree.size() ; i ++){
			cout<< tree[i].first <<" " << tree[i].second << endl;
		}
	}
}