#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int n;

int dfs(ll x, bool a, bool b, bool c) {
    if (x > n) return 0;
    return dfs(x * 10 + 3, true, b, c) 
         + dfs(x * 10 + 5, a, true, c)
         + dfs(x * 10 + 7, a, b, true)
         + (a && b && c);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cout << dfs(0, false, false, false) << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/