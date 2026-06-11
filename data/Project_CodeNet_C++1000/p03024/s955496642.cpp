#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	string s;
	cin >> s;
	int cnt=0;
	rep(i,s.size()){
		if(s[i]=='x') cnt++;
	}
	if(cnt<=7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;\
	return 0;
}

