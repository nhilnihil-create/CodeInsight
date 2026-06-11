#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<lli,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int inf = 1e9;
const int maxn = 305;
Double dp[maxn][maxn][maxn];
int cnt[4];
int main(){__
	int n;
	cin >> n;
	for(int i=1; i <=n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}

	dp[cnt[3]][cnt[2]][cnt[1]] = 1.0;
	Double ans = 0.0;
	cout << fixed << setprecision(10);
	for(int i= maxn-1; i >=0; i--){
		for(int j=maxn-1; j>=0; j--){
			for(int k=maxn-1; k>=0; k--){
				if(!j && !i && !k) continue;
				Double todas = i+j+k;
				//Pongo mi valor
				ans+= dp[i][j][k] * (1.0 / (todas/Double(n)));
				//cout << "ans suma " << ans << endl;
				//paso proba a las demas
				if(i-1 >=0)
					dp[i-1][j+1][k]+= (dp[i][j][k] * (Double(i)/todas));
				if(j-1 >=0)
					dp[i][j-1][k+1]+= (dp[i][j][k] * (Double(j)/todas));
				if(k-1 >=0)
					dp[i][j][k-1]+= (dp[i][j][k] * (Double(k)/todas));
			}
		}
	}
	cout << ans << endl;
	return 0;
}

