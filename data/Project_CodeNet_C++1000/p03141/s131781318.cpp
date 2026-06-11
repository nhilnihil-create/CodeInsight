#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    
    cin>>n;
    ll res = 0;
    vector<ll> v;
    for (int i=0; i<n; i++) {
	ll a, b;
	cin>>a>>b;
	res -= b;
	v.push_back(a+b);
    }

    sort(v.rbegin(), v.rend());

    for (int i=0; i<n; i+=2) {
	res += v[i];
    }

    cout<<res<<endl;    
    
    return 0;
}
