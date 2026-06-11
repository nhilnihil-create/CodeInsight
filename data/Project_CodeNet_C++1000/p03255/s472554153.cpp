#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int sum[214514],kei[214514];
signed main(){
	int n,cost;
	cin>>n>>cost;
	vector<int> pos;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		pos.pb(x);
	}
	reverse(pos.begin(), pos.end());
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + pos[i-1];
	}
	kei[1] = 5;
	for(int i=2;i<=n;i++){
		kei[i] = 1+2*i;
	}
	int ans = -1;
	for(int k=1;k<=n;k++){	// goes and returns k times
		int num = n/k;
		if(n%k)num++;
		int tmp = 0;
		int cur = 0;
		for(int i=1;i<=num;i++){
			tmp += kei[i] * ( sum[min(cur+k,n)] - sum[cur] );
			cur += k;
		}
		tmp += cost * ( n + k );
		//cout<<k<<" "<<tmp<<endl;
		if( tmp < ans || ans < 0 )ans = tmp;
	}
	cout<<ans<<endl;
	return 0;
}