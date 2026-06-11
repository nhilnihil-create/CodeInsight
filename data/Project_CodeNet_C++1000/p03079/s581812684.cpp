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
	set<int> side; side.clear();
	rep (i, 3){
		int in; cin >> in;
		side.insert(in);
	} // end rep

	cout << ((int)side.size() == 1 ? "Yes" : "No") << endl;

	return 0;
}