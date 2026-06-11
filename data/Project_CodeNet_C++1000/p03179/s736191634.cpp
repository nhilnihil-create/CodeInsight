#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<queue>
#include<unordered_map>
#include<map>
#include<stack>
#include<bits/stdc++.h>
#include<string.h>
#include <ext/pb_ds/assoc_container.hpp>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define f first
#define respr(fir,sec) for(int i=0;i<=fir;i++){for(int j=0;j<=sec;j++){cout << res[i][j] << " ";}cout << "\n";}
#define pb push_back
#define vint vector<int>
const int mod = 1000000007;
using namespace std;
const int maxsize=3005;
int dp[maxsize][maxsize];
int pref[maxsize][maxsize];


void assignee(int &x, int ans)
{
	x += ans;
	x %= mod;
}



int32_t main()
{
	//freopen("input.txt", "r" , stdin);
	int n;
	string s;
	cin >> n >> s;
	
	dp[1][1] = 1;
	
	for(int len=2; len <=n;len++)
	{
		for(int i=1;i<=len-1;i++)
		{
			pref[len-1][i] = (pref[len-1][i-1]+dp[len-1][i])%mod;
		}
		
		int L,R;
		for(int b=1;b<=len;b++)
		{
			if(s[len-2] == '<')
			{
				L=1;
				R = b-1;
			}
			else
			{
				L=b;
				R = len-1;
			}
			if(L<=R)
				assignee(dp[len][b], (pref[len-1][R]-pref[len-1][L-1]+mod)%mod);
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		assignee(ans,dp[n][i]);
	}
	cout << ans << "\n";
	return 0;
}
