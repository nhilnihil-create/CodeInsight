#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n;
	cin >> n;
	vector<int> a(0);
	rep(i, 26) rep(j, 16){
		a.push_back(i*4+j*7);
	}
	sort(a.begin(), a.end());
	int f = 0;
	rep(i, a.size()){
//		cout << a.at(i) << ' ';
		if(a.at(i) == n) f = 1;
	}
	if(f == 1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}