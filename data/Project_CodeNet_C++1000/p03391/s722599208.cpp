#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int n;
ll a[maxn];
ll b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    
    cin>>n;
    bool same = true;
			 
    for (int i=0; i<n; i++) {
	cin>>a[i]>>b[i];
	if (a[i]!=b[i]) same = false;	
    }

    if (same) out(0);

    // Player 1 can always stall out by keeping at least 1 a[i]>b[i], and decreasing everything else
    // Meanwhile, player 2 just needs to always be making moves such that b[i]>a[i] to stay productive.
    // Player 1 will pick the a[i]>b[i] such that b[i] is smallest to stall out for as long as possible.

    ll res = 0;
    for (int i=0; i<n; i++) {
	res += a[i];
    }

    ll bmin = 1e9;
    for (int i=0; i<n; i++) {
	if (a[i] > b[i]) {
	    bmin = min(bmin, b[i]);
	}
    }

    res -= bmin;

    cout<<res<<endl;    
    return 0;
}
