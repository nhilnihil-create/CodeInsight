#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> g;
vector<int> o;
map<int, int> ad;
vector<ll> c;

int main(){
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	vector<string> a(0);
	vector<string> b(1);
	rep(i, s.size()){
		int l = min(n-i+1, 6);
		for(int j=1; j<l; j++){
			a.push_back(s.substr(i, j));
	//		cout << i << ' ' << j << ' ' << s.substr(i, j) << endl;
		}
	}
	sort(a.begin(), a.end());/*
	rep(i, a.size()) cout << a.at(i) << ' ';
	cout << endl;*/
	b.at(0) = a.at(0);
	rep(i, a.size()-1) if(a.at(i) != a.at(i+1)) b.push_back(a.at(i+1));
	cout << b.at(k-1) << endl;
	return 0;
}