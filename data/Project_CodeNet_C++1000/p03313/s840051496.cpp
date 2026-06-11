#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;
const int inf = 1e9;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n;
    cin>>n;
    
    n = 1<<n;
    vector<int> a(n+10);
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    int best = 0;

    for (int k=1; k<=n-1; k++) {
	int x1 = -inf, x2 = -inf;
	for (int mask=k; ; mask=(mask-1)&k) {
	    int cur=a[mask];
	    if (cur >= x1) {
		x2 = x1;
		x1 = cur;
	    } else if (cur >= x2) {
		x2 = cur;
	    }
	    best = max(best, x1+x2);
	    if (mask==0) break;
	}

	cout<<best<<"\n";
    }
    
    return 0;
}
