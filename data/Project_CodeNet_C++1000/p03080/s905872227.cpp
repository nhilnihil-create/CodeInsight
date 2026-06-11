#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int r_cnt=0;
	rep(i,s.size()){
		if(s[i]=='R')
			r_cnt++;
	}
	int b_cnt = n-r_cnt;
	if(r_cnt>b_cnt)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

