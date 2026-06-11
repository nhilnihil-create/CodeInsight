#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

inline void add(vector<pair<int, pair<int, int> > > &v, int l, int r, int ch){
	if(v.empty() || v.back().first != ch)v.push_back({ch, {l, r}});
	else v.back().second.second = r;
}

inline void reduce(vector<pair<int, pair<int, int> > > &v, int r){
	while(v.back().second.second > r){
		if(v.back().second.first > r){
			v.pop_back();
		}else{
			v.back().second.second = r;
		}
	}
}

inline void process(vector<pair<int, pair<int, int> > > &v, int len, int sz){
	while(v.back().first == sz){
		v.pop_back();
	}
	int ch = v.back().first;
	int l = v.back().second.first;
	int r = v.back().second.second;
	v.pop_back();
	if(l == r){
		add(v, l, r, ch + 1);
	}else{
		add(v, l, r - 1, ch);
		add(v, r, r, ch + 1);
	}
	if(r != len){
		add(v, r + 1, len, 1);
	}
}

inline bool isPossible(vector<int> &a, int sz){
	vector<pair<int, pair<int, int> > > vec;
	int prev = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] > prev){
			add(vec, prev + 1, a[i], 1);
		}else{
			reduce(vec, a[i]);
			if(vec.size() == 1 && vec[0].first == sz)return false;
			process(vec, a[i], sz);
		}
		prev = a[i];
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int l = 1, r = n;
	while(l < r){
		int m = l + (r - l)/2;
		if(isPossible(a, m))r = m;
		else l = m + 1;
	}
	cout<<l<<endl;

	return 0;
}