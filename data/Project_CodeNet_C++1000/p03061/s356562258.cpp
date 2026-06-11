#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, pgf[100001], pgb[100001], ans = 0;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> pgf[i]; pgb[i] = pgf[i];
	}

	for(int i = 2; i<=n; i++)
		pgf[i] = __gcd(pgf[i],pgf[i-1]);
	
	for(int i = n-1; i>=1; i--)
		pgb[i] = __gcd(pgb[i], pgb[i+1]);

	ans = max(pgf[n-1], pgb[2]);
	for(int i = 2; i<=n-1; i++)
		ans = max(ans, __gcd(pgf[i-1], pgb[i+1]));
	
	cout << ans << endl;

	cout.flush();
	return 0;
}