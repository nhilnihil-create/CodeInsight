#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;




int n;
ll c[maxn], s[maxn], f[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;

    for (int i=0; i<n-1; i++) {
	cin>>c[i]>>s[i]>>f[i];
    }

    for (int i=0; i<n; i++) {
	if (i==n-1) {
	    out(0);
	}
	ll t=0;
	for (int j=i; j<n-1; j++) {
	    if (t<s[j]) {
		t=s[j];
	    } else {
		t=(t+f[j]-1)/f[j]*f[j];
	    }
	    t+=c[j];
	}
	cout<<t<<"\n";
    }
  

    return 0;
}
