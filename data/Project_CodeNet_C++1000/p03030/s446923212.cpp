#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<tuple<string,int,int>> cnt;
	rep(i,n){
		string s;
		int p;
		cin >> s >> p;
		p = -p;
		cnt.push_back(tie(s,p,i));
	}
	sort(cnt.begin(),cnt.end());
	rep(i,n){
		cout << get<2>(cnt[i])+1 << endl;
	}
}

// cout << fixed << setprecision(15) <<  << endl;