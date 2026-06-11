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
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int dif1 = x2 - x1, dif2 = y2 - y1;
	cout << x2 - dif2 << " " << y2 + dif1 << " " << x1 - dif2 << " " << y1 + dif1 << endl; 
} 