#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>
#define ll long long
#define rep(i, n) for(i=0; i<n; i++)
#define rep1(i, n) for(i=1; i<=n; i++)
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, i, count = 0;
	cin >> n >> m;
	ll l, r, lm=0, rm=INT_MAX;
	rep(i, m){
		cin >> l >> r;
		lm = max(l, lm);
		rm = min(r, rm);
	}
	rep1(i, n){
		count = (i>=lm && i<=rm)? count+1 : count;
	}
	cout << count << endl;
	return 0;
}
