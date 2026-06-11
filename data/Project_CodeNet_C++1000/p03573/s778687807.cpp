#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
static const int INF = 10000000;
using ll = long long;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(a == b) cout << c << endl;
	if(b == c) cout << a << endl;
	if(a == c) cout << b << endl;
	return 0;
}

