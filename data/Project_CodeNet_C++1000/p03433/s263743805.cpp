#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int N, A;
	cin >> N >> A;
	if (N >= 500) N %= 500;
	string ans;
	if (N <= A){
		ans = "Yes";
	}
	else{
		ans = "No";
	}
	cout << ans << endl;
	return 0;
}
