#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define vi vector<int>
#define ii pair<int, int>
#define ll long long int
#define MAX 200010
#define MOD 1e9+7
#define endl '\n'
using namespace std;

int main()
{
   
	fastio;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, x;
	cin >> n >> x;

	int v[n];
	REP(i, 0, n){
		cin >> v[i];
	}

	sort(v, v+n);

	int ans = n;
	int sum = accumulate(v, v+n, 0);
	
	x-=sum;

	ans += floor((double)x/v[0]);

	cout << ans << endl;

    return 0;
}