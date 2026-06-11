#include<bits/stdc++.h>

#define ll long long 
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define in insert
#define pii pair<int, int>
#define pll pair<ll, ll>
#define N int(1e5) + 5
#define T int(1e4) + 5
#define H int(1e3) + 55

using namespace std;

ll n, m, a, sum, num, sam, nam, maxi, mini;

int main() {
	cin >> n >> m >> a;
	if(abs(m - a) % 2 == 0) {
	 	cout << "Alice";
	 	return 0;
	}
	else {
	 	cout << "Borys";
	 	return 0;
	}
}