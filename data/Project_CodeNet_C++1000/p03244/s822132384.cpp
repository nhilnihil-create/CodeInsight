#include "bits/stdc++.h"
using namespace std;

//23
typedef long long ll;
			
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	map<int,int> m1;
	map<int,int> m2;
	for (int i = 0; i < n; i += 2) {
		m1[v[i]]++;
	}
	for (int i = 1; i < n; i += 2) {
		m2[v[i]]++;
	}
	set<pair<int,int>> p1;
	set<pair<int,int>> p2;
	for (auto it = m1.begin(); it != m1.end(); ++it) {
		p1.insert({it->second,it->first});
	}
	for (auto it = m2.begin(); it != m2.end(); ++it) {
		p2.insert({it->second,it->first});
	}
	auto it1 = p1.rbegin(); 
	auto it2 = p2.rbegin();
	if (it1->second != it2->second) { 
		//cout << "";
		cout << n - it1->first - it2->first;
	}else {
		if ((int)p1.size() == 1 && (int)p2.size() == 1) {
			cout << n - max(it1->first,it2->first);
		}else if ((int)p1.size() == 1) {
			//cout << "hello";
			++it2;
			cout << n - it1->first - it2->first; 
		}else if ((int)p2.size() == 1) {
			++it1;
			cout << n - it1->first - it2->first;
		}else {
			auto it3 = it1;
			auto it4 = it2;
			++it1;
			++it2;
			cout << n - max(it3->first + it2->first, it1->first + it4->first);
		}	
	}
}
