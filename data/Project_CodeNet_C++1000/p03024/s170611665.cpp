#include <bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);
using namespace std;

int main() {
    IOS
	string s;
	cin >> s;
  	int cnt = 0;
  	for (int i = 0; i < (int) s.size(); ++i) {
    	cnt += s[i]=='x';
    }
  	cout << (cnt > 7 ? "NO": "YES") << endl;
    return 0;
}

