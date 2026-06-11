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

    int n;
    cin>>n;
    vector<int> a(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
	cin>>a[i];
	sum += a[i];
    }

    int idx = 0;
    for (int i=1; i<n; i++) {
	if (abs(n*a[idx]-sum) > abs(n*a[i]-sum)) {
	    idx = i;
	}
    }

    cout<<idx<<endl;    
    return 0;
}
