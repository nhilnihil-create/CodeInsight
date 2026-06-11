#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int N;

double arr[3005];

double dp[3005][3005];

bool visited[3005][3005];


double headsProbability(int n, int H)
{

	if (n == 0) {

		if (H * 2 >= N)
			return 1;
		else return 0;

	}


	if (visited[n][H])
		return dp[n][H];


	visited[n][H] = 1;


	double heads = (arr[n - 1]) * headsProbability(n - 1, H + 1);

	double tails = (1 - arr[n - 1]) * headsProbability(n - 1, H);

	return  dp[n][H] = heads + tails;


}





int32_t main()
{


	cin >> N;


	for (int i = 0; i < N; ++i)
		cin >> arr[i];


	memset(visited, 0, sizeof(visited));

	memset(dp, 0, sizeof(dp));

	double ans = headsProbability(N, 0);

	printf("%.15g\n", ans);


}