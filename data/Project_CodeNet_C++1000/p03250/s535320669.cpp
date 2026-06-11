#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const double pi = 3.14159265358979323846;
const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int a, b, c; cin >> a >> b >> c;
	if(a >= b && a >= c) cout << 10*a + b + c;
	else if(b >= a && b >= c) cout << 10*b + a + c;
	else if(c >= a && c >= b) cout << 10*c + a + b;
} 