#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int

ll a[MAXX];
multiset<ll> ms;
multiset<ll>::iterator it;
signed main()
{
    FAST;
    ll n;
    ll b;
    cin >> n >> b;
    if(n > b){
    	cout << 2*n - 1;
	}
	else if(n < b){
		cout << 2*b - 1;
	}
	else{
		cout << n + b;
	}
}