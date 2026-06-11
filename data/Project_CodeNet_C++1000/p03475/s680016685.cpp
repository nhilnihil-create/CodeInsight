#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000000

int main(){
	int n;cin>>n;
	vector<int> c(n-1),s(n-1),f(n-1);
	for(int i=0;i<n-1;i++){
		cin>>c[i]>>s[i]>>f[i];
	}

	vector<int> ans(n,0);
	for(int i=0;i<n;i++){
		ans[i]=s[i]+c[i];//とりあえず次の駅へ行くまでの時間を入れる
	}

	for(int i=0;i<n-2;i++){//i駅について
		for(int j=i+1;j<n-1;j++){
			ans[i]=s[j]+max(0,(ans[i]-s[j]+f[j]-1)/f[j])*f[j];//s[次の駅]が到着時間より遅ければ、ans=s[次の駅]  //　そうでなければ、できるだけ早い電車に乗る
			ans[i]+=c[j];//次の駅へ行く所要時間
		}
	}

	for(int i=0;i<n-1;i++){
		cout<<ans[i]<<endl;
	}
	cout<<0<<endl;
	return 0;
}