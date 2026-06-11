#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


ll ans=0;
void dfs(int i,string num,ll N,vector<bool> used)
{
	if(num.size()>=10||(ll)atoi((num.c_str()))>N) return;
	//cout<<(ll)atoi((num.c_str()))<<endl;
	if(used[3]&&used[5]&&used[7]) ans++;
	int use_num[3]={3,5,7};
	for(int x : use_num)
	{
		bool prev=true;
		if(!used[x]) prev=false;
		used[x]=true;
		if(num.size()<=i) num+=(char)(x+'0');
		else num[i]=(char)(x+'0');
		dfs(i+1,num,N,used);
		used[x]=prev;
	}
}
int main()
{
	ll N;
	cin>>N;
	vector<bool> used(10,false);
	dfs(0,"",N,used);
	cout<<ans<<endl;
	return 0;
}
