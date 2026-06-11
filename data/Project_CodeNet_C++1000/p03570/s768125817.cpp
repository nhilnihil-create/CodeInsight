#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


string str;
int cnt[200005][27];
vector<int> bit[200005];
int dp[200005];
int bs[200005];
vector<int> bits;
int dp2[200005];

int main(void){
	cin >> str;
	int n=str.size();
	for(int i=0;i<n;i++){
		cnt[i+1][str[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<n;j++){
			cnt[j+1][i]+=cnt[j][i];
		}
	}
	for(int i=0;i<n;i++){
		int bi=0;
		for(int j=0;j<26;j++){
			if(cnt[i+1][j]%2==1)bi+=(1<<j);
		}
		bs[i+1]=bi;
		bits.push_back(bi);
	}
	bits.push_back(0);
	sort(bits.begin(),bits.end());
	bits.erase(unique(bits.begin(),bits.end()),bits.end());
	bit[0].push_back(0);
	for(int i=0;i<n;i++){
		int v=lower_bound(bits.begin(),bits.end(),bs[i+1])-bits.begin();
		bit[v].push_back(i+1);
	}
	for(int i=0;i<=n;i++){
		dp[i]=n;
	}
	dp[0]=0;
	for(int i=0;i<bits.size();i++){
		dp2[i]=n;
	}
	dp2[0]=0;
	for(int i=1;i<=n;i++){
		int nbit=bs[i];
		int nbit2=lower_bound(bits.begin(),bits.end(),bs[i])-bits.begin();
		if(nbit2!=bits.size() && bits[nbit2]==nbit){
			dp[i]=min(dp2[nbit2]+1,dp[i]);
		}
		for(int j=0;j<26;j++){
			int nnbit=bs[i];
			if(nnbit>>j & 1){
				nnbit-=1<<j;
			}else{
				nnbit+=1<<j;
			}
			int nnbit2=lower_bound(bits.begin(),bits.end(),nnbit)-bits.begin();
			if(nnbit2==bits.size() || bits[nnbit2]!=nnbit)continue;
			dp[i]=min(dp[i],dp2[nnbit2]+1);
		}
		dp2[nbit2]=min(dp2[nbit2],dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}