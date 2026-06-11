#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;


int n,k,q;
int ans=2e9;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>k>>q;
    a.resize(n);
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    for (int x: a) {
	multiset<int> s;
	vector<int> v;
	for (int i=0; i<=n; i++) {
	    if (i==n||a[i]<x) {
		sort(v.rbegin(), v.rend());
		while ((int)v.size() >= k) {
		    s.insert(v.back());
		    v.pop_back();
		}
		v.clear();
	    } else {
		v.push_back(a[i]);
	    }
	}
	if ((int)s.size()<q) continue;
	auto iter=s.begin();
	for (int j=0; j<q-1; j++) iter++;
	ans=min(ans,*iter-x);
    }
    cout<<ans<<endl;  

    return 0;
}
