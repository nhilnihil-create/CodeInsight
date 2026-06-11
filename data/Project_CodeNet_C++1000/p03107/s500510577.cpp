#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int nz = 0, no = 0;
    for (auto i : s) {
        if (i == '1') no++;
        else nz++;
    }
    cout << min(nz, no) * 2 << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/