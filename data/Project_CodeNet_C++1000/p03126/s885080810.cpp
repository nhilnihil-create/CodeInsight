#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n, m;
int f[maxn];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>m;
    for (int i=0; i<n; i++) {
	int k;
	cin>>k;
	while (k--) {
	    int x;
	    cin>>x;
	    f[x]++;
	}
    }

    int res = 0;
    for (int i=1; i<=m; i++) {
	res += (f[i]==n);
    }
    out(res);
    
    return 0;
}
