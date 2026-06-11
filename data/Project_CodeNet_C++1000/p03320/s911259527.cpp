#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


ll S(ll x) {
    ll res = 0;
    while (x) {
	res += (x%10);
	x /= 10;
    }
    return res;
}


bool snuke(ll n) {

    for (ll i=n+1; i<=n*10; i++) {
	if (n*S(i) > i*S(n)) return false;
    }
    return true;
}

ll k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>k;

    // for (ll i=1; i<=100000; i++) {
    // 	if (snuke(i)) watch(i);
    // }


    // Let f(N): n>=N that minimizes n/S(n)
    // motivation: If we can build f(N), then we can repeatedly iterate on N to get all K terms.
    
    // Minimizing n/S(n) more or less means maximizing S(n),
    // so an intuitive guess for n would mean it has a lot of 9's.
    
    // In fact, n is of the form N1,N2,N3...d,9,9,9..9, where d is the first digit that differs from N.
    // Proof: Suppose for sake of contradiction that n doesn't have a suffix of all 9's,
    // so it looks like N1,N2,N3,d,9,9,..3,..9,9.
    // Let x < n, and x = N1,n2,n3,d-1,9,9,9,9...9.
    // but x < n and S(x) >= S(n), which means x/S(x) <= n/S(n), which violates our min criteria, so we've
    // come full circle on the fact that n actually contains a suffix of 9's.

    ll add = 1;

    cout<<1<<endl;
    ll cur=1;
    for (int it=2; it<=k; it++) {
	ll nxt=cur+add;
	ll nxt2 = nxt+add;
	if (nxt*S(nxt2) > nxt2*S(nxt)) {
	    add *= 10ll;
	    nxt = cur + add;
	}
	cur = nxt;
	cout<<cur<<"\n";
    }
    
    return 0;
}
