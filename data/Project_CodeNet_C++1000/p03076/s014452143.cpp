#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 100000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;



int main() {
	int A, B, C, D, E;
	int tmp,div,ans=0,buf=0;
	rep(i, 5) {
		cin >> tmp;
		if (tmp%10!=0)
		{
			div = tmp / 10 * 10 + 10;
			buf = max(buf, div - tmp);
			ans += div;
			
		}
		else {
			div = tmp;
			ans += div;
		}
	}
	cout << ans - buf << endl;
}