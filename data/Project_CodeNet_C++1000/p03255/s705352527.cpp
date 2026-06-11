#include<bits/stdc++.h>
using namespace std;

long long int p[200010],s[200010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>p[i],s[i]=s[i-1]+p[i];
	long long int ans = 1e18;
	for(int k=1;k<=n;k++){
		int c = 3;
		long long int cur = 0;
		for(int j=n;j>0;j-=k){
			if(cur>ans)	break;
			long long int now = s[j]-s[max(j-k,0)];
			cur += now * max(5,c);
			c+=2;
		}
		ans = min(ans,cur+(k+n)*1LL*x);
	}
	cout<<ans<<endl;
}
