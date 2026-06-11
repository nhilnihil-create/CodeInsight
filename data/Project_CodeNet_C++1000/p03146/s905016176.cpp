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

    int s;
    cin>>s;
    set<int> viz;
    for (int i=1;;i++) {
	if (viz.count(s)) {
	    out(i);
	}
	viz.insert(s);
	if (s%2) {
	    s=3*s+1;
	} else {
	    s /= 2;
	}
    }
    
    
    return 0;
}
