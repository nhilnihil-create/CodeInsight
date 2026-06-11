#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	int final_start, final_end;
	cin >> final_start >> final_end;
	for (int i = 1; i<m && final_start <= final_end; i++) {
		int curr_start, curr_end; cin >> curr_start >> curr_end;
		final_start = max(final_start, curr_start);
		final_end = min(final_end, curr_end);
	}
	cout << max(final_end - final_start + 1, 0) << '\n';
	
}

