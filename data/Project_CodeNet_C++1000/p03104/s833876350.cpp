#include <bits/stdc++.h> 
using namespace std; 
typedef unsigned long long ll;

ll f(ll a) {
    ll res[] = {a, 1, a+1, 0};
    return res[a%4];
}

ll getXor(ll a, ll b) {
    return f(b) ^ f(a-1);
}

int main() 
{ 
	ll l, r;
	cin >> l >> r;
	cout << getXor(l, r) << "\n";
	return 0; 
} 
