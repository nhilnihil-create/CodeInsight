#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    const string S = "keyence";

    string s;
    cin>>s;
    int n = s.length();

    if (s == S) out("YES");

    for (int i=0; i<n; i++) {
	for (int j=i; j<n; j++) {
	    string cur;
	    for (int k=0; k<n; k++) {
		if (i<=k && k<=j) continue;
		cur += s[k];
	    }
	    if (cur==S) out("YES");
	}
    }

    out("NO");
    
    
    return 0;
}
