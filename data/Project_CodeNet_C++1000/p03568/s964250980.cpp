#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back
#define Cout(s) cout << s << endl
string Yes(bool b) {if(b){return "Yes";} else {return "No";}}
string YES(bool b) {if(b){return "YES";} else {return "NO";}}


int main(){
	int N;
	cin >> N;
	vector<i64> A(N);
	rep(i, N) cin >> A[i];

	auto dfs = [&](auto&& _dfs,int i,  i64 p) -> int {
		if(i == N) return (p % 2 == 0);

		int ans = 0;
		ans += _dfs(_dfs, i+1, p*A[i]);
		ans += _dfs(_dfs, i+1, p*(A[i] - 1));
		ans += _dfs(_dfs, i+1, p*(A[i] + 1));

		return ans;
	};

	Cout(dfs(dfs, 0, 1));
}
