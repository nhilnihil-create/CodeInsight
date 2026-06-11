#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100][2];
int main()
{
	ll n,k;
	cin >> n >> k;
	ll K = k;
	vector<ll> a(n),b;
	for(int i = 0;i<n;i++)cin >> a[i];
	while(k)
	{
		b.emplace_back(k%2);
		k/=2;
	}
	reverse(b.begin(),b.end());
	ll bn = b.size();
	dp[0][0] = 0;
	dp[0][1] = 1LL<<(bn-1);

	for(int i = 1;i<bn;i++)
	{
		if(b[i]==0)//未満は1と0に分岐、そうじゃなければ、0
		{
			dp[i][1] = dp[i-1][1];
			ll hoge = dp[i-1][0];
			ll sum = 0;
			for(int j = 0;j<n;j++) sum += a[j] ^ hoge;
			ll sum2 = 0;
			ll hoge2 = dp[i-1][0] + (1LL<<(bn - i -1));
			for(int j = 0;j<n;j++) sum2 += a[j] ^ hoge2;
			if(sum2 > sum) dp[i][0] = hoge2;
			else dp[i][0] =  hoge;
		}
		else{
			ll sum[2]={}, bit[2] = {};
			//まず、dp[i][0]の3つの候補を決める
			bit[0] = dp[i-1][0];
			for(int j = 0;j<n;j++) sum[0] += a[j] ^ bit[0];
			if(sum[1]<sum[0]){sum[1] = sum[0];bit[1] = bit[0];}sum[0] = 0;bit[0] = dp[i-1][0] + (1LL<<(bn - i - 1));
			for(int j = 0;j<n;j++)sum[0] += a[j] ^bit[0];
			if(sum[1]<sum[0]){sum[1] = sum[0];bit[1] = bit[0];}sum[0] = 0;bit[0] = dp[i-1][1];
			for(int j = 0;j<n;j++)sum[0] += a[j] ^bit[0];
			if(sum[1]<sum[0]){sum[1] = sum[0];bit[1] = bit[0];}
			dp[i][0] = bit[1];
			dp[i][1] = dp[i-1][1] + (1LL<<(bn-i-1));
		}
	}
	ll ans[2] = {};
	if(K==0)
	{
		dp[0][0] = dp[0][1] = 0;
		bn=1;
	}
	//cout << bn << endl;
	//cout << dp[bn-1][1]<< ' ' << dp[bn-1][0] << endl;
	//for(int i = 0;i<2;i++){for(int j = 0; j<bn;j++){cout << dp[j][i] << ' ';}cout << endl;}
	for(int i = 0;i<n;i++)
	{
		ans[1] += a[i]^dp[bn-1][1];
		ans[0] += a[i]^dp[bn-1][0];

	}
	cout << max(ans[1],ans[0])<<endl;
}
