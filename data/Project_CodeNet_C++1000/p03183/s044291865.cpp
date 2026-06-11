#include "bits/stdc++.h"
using namespace std;

#define show(x) cerr << #x << " = " << x << endl ;
#define input_from_file freopen("input.txt","r",stdin)
#define output_to_file freopen("output.txt" , "w",stdout)
#define fastio ios_base::sync_with_stdio(0)
#define endl '\n'

const int N = 1e3+1 , W = 2e4+5;
vector < vector < int > > v(N , vector < int > (3));
long long dp[W][N];
bool compare(vector < int > &v1 , vector < int > &v2)
{
	return (v1[0] + v1[1] < v2[0] + v2[1]);
}
int main()
{
	 #ifdef LOCAL
        input_from_file;
        output_to_file;
    #endif
	fastio;cin.tie(0);cout.tie(0);
	int n ; cin >> n ;
	for(int i = 1 ; i <= n ; ++i)
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	sort(v.begin()+1 , v.begin()+n+1 , compare);
	for(int i = 0 ; i < W ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			dp[i][j] = max(dp[i][j] , dp[i][j-1]);
			if(v[j][1] >= i && v[j][0] + i < W)
			{
				dp[i+v[j][0]][j] = max(dp[i+v[j][0]][j] , dp[i][j-1] + v[j][2]);
			}
		}
	}
	long long ans = INT_MIN;
	for(int i = 1 ; i < W ; ++i)
		ans = max(dp[i][n] , ans);
	cout << ans;

	return 0;
}