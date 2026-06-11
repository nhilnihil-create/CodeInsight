#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;

const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int r, x, d; cin >> r >> d >> x;
	for(int i = 0; i < 10; i++){
		cout << r * x - d << endl;
		x = r * x -d;
	}

} 