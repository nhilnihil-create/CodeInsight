#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	vector<int> v(4);
	rep(i,4) v[i] = s[i] - '0';
	rep(is,1<<3){
		int tmp = v[0];
		rep(j,3){
			if(is>>j&1) tmp += v[j+1];
			else tmp -= v[j+1];
		}
		if(tmp == 7){
			cout << v[0];
			rep(j,3){
				if(is>>j&1) cout << '+';
				else cout << '-';
				cout << v[j+1];
			}
			cout << "=7" << endl;
			return 0;
		}
	}
}