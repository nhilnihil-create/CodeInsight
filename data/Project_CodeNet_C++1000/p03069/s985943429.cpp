#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> wh(n);
	vector<int> br(n);
	int whi = 0;
	int brk = 0;
	rep(i, n){
		if(s.at(i) == '.') whi++;
		else brk++;
		wh[i] = whi;
		br[i] = brk;
	}
	int mi = 1000000;
	rep(i, n-1){
		int sum = whi - wh[i] + br[i];
		if(mi > sum) mi = sum;
	}
	cout << min(min(mi, brk), whi) << endl;
	return 0;
}