#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2*(18+2);
int n;
char s[maxn],t[maxn];
vector<int> a,b;
ll ans;

void dfs(int pos){
	if(pos>=n){
		static int dp[20][20];
		for(int i=0;i<=a.size();++i)
			for(int j=0;j<=b.size();++j)
				dp[i][j]=0;
		dp[0][0]=1;
		for(int i=0;i<=a.size();++i)
			for(int j=0;j<=b.size();++j){
				if(i<a.size()&&t[i+j]==a[i])
					dp[i+1][j]+=dp[i][j];
				if(j<b.size()&&t[i+j]==b[j])
					dp[i][j+1]+=dp[i][j];
			}
		ans+=dp[a.size()][b.size()];
		return;
	}
	a.push_back(s[pos]);
	dfs(pos+1);
	a.pop_back();
	b.push_back(s[pos]);
	dfs(pos+1);
	b.pop_back();
}

int main(){
	cin>>n;
	cin>>s;
	for(int i=0;i<n;++i)
		t[i]=s[2*n-1-i];
	dfs(0);
	cout<<ans<<endl;
	return 0;
}