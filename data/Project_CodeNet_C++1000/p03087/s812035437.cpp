#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
using ll = long long;


template<class T>inline bool chmax(T& a, T b){if(a<b) { a=b;return true; } return false;}
template<class T>inline bool chmin(T& a, T b){if(a>b) { a=b;return true; } return false;}

int main(){
	int n,q;cin >> n >> q;
	string s;cin >> s;
	vector<int> l(q);
	vector<int> r(q);
	for(int i=0;i<q;i++){
		cin >> l.at(i) >> r.at(i);
	}
	vector<int> ruiseki(n,0);
	for(int i=0;i<n;i++){
		ruiseki[i+1] = ruiseki[i];
		if(s[i] == 'A'){
			if(s[i+1] == 'C'){
				ruiseki[i+1]++;
			}
		}
	}
	for(int i=0;i<q;i++){
		int lnum = l[i];
		int rnum = r[i];
		cout << ruiseki[rnum-1] - ruiseki[lnum-1] << endl;
	}
}
