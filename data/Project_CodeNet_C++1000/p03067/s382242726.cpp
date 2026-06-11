#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	if(a<c&&c<b||b<c&&c<a)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

