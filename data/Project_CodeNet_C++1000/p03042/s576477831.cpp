#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int s;
	cin >> s;
	int l, r;
	r = s % 100;
	l = (s - r)/100;
	if (r == 0) {
		if (l == 0 || l >= 13)cout << "NA";
		else cout << "MMYY";
	}
	else if (l==0) {
		if (r >= 13)cout << "NA";
		else cout << "YYMM";
	}
	else if (r >= 13 && l <= 12) {
		cout << "MMYY";
	}
	else if (r <= 12 && l >= 13) {
		cout << "YYMM";
	}
	else if (r >= 13 && l >= 13){
		cout << "NA";
	}
	else{
		cout << "AMBIGUOUS";
	}

	return 0;
}