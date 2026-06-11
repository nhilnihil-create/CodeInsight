#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string S; cin >> S;
	int w; cin >> w;
	int n = (int)S.length();

	string res = "";
	rep (i, n){
		if (i % w == 0){
			res += S[i];
		} // end if
	} // end rep

	cout << res << endl;

	return 0;
}