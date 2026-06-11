#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 200105;

ll dp[1001][20001];
void go() {
	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>>v;
	f(n) {
		int x, y, z;
		cin >> x >> y >> z;
		v.pb({{x,y},z});
	}
	sort(all(v),[](pair<pair<int,int>,int>x,pair<pair<int,int>,int>y) {
		return x.F.F + x.F.S < y.F.F + y.F.S;
	});
	int ptr = 0;
	ll mx = 0;
	for (auto &i : v) {
		int lim = i.F.S;
		for (int j = 0 ; j <= 20000 ; j++) {
			dp[ptr + 1][j] = max(dp[ptr][j], dp[ptr+1][j]);
			if (j<=lim) {
				dp[ptr+1][j + i.F.F] = dp[ptr][j] + i.S;
				mx = max(mx, dp[ptr][j] + i.S);
			}
		}
		ptr++;
	}
	cout << mx << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}