#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#include<unordered_map>
unordered_map<int,vector<int> >v;
//vector<int> v[1<<26];
int mark[200010];
int dp[200010];
int main(){
	string s;
	cin>>s;
	int r=1;
	lol(i,26)r*=2;
	lol(i,s.size()+1)dp[i]=mod;
	dp[0]=0;
	mark[0]=0;
	int cnt[26]={0};
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
		cnt[s[i]-'a']%=2;
		int tmp=0;
		int a=1;
		lol(j,26){
			tmp+=a*cnt[j];
			a*=2;
		}
		v[tmp].push_back(i+1);
		mark[i+1]=tmp;
	}

	for(int i=0;i<s.size();i++){
		int k=mark[i];
		
		if(upper_bound(v[k].begin(),v[k].end(),i)!=v[k].end()){
			int it=*upper_bound(v[k].begin(),v[k].end(),i);
			dp[it]=min(dp[it],dp[i]);
		}
		int a=1;
		for(int j=0;j<26;j++){
			int tmp=mark[i];
			if(mark[i]%(a*2)<a){
				tmp+=a;
			}
			else tmp-=a;
			//tmpが,mark[i]から1bitだけ変化したもの
			a*=2;
			k=tmp;
			if(upper_bound(v[k].begin(),v[k].end(),i)!=v[k].end()){
				int it=*upper_bound(v[k].begin(),v[k].end(),i);
				dp[it]=min(dp[it],dp[i]+1);
			}
		}
		//cout<<dp[i]<<" ";
	}
	cout<<max(1,dp[s.size()])<<endl;
	return 0;
}
