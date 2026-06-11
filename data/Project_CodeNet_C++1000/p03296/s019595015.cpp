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
#define T int(1e4) + 55
#define H int(1e3) + 55
#define mp make_pair

using namespace std;

string  w;
ll n, sum, num, sam, nam, q[N];

int main() {
	cin >> n ;
	for(int i = 0;i < n; ++ i) {
	 	cin >> q[i];
	}
	for(int i = 0;i < n; ++ i) {
		if(q[i] == q[i + 1]) {
		 	sum ++;
     	}
     	else {
     	    num += (sum + 1) / 2;
     	    sum = 0;
     	}	
	}
	num += (sum + 1) / 2;
	cout << num ;
	return 0;
}