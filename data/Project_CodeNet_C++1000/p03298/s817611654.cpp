#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<pair<string,int>,int> cnt[2];
	int n;
	string s;
	cin>>n>>s;
	for(int i=0;i<(1<<n);i++){
		string str[2][2];
		for(int j=0;j<n;j++)
			for(int k=0;k<2;k++)
				if((i>>j)&1)
					str[k][1]+=s[k*n+j];
				else
					str[k][0]+=s[k*n+j];
		reverse(str[0][1].begin(),str[0][1].end());
		reverse(str[1][1].begin(),str[1][1].end());
		int x = __builtin_popcount(i);
		cnt[0][make_pair(str[0][0]+str[0][1],x)]++;
		cnt[1][make_pair(str[1][1]+str[1][0],n-x)]++;
	}
	long long int ans = 0;
	for(auto it:cnt[0]){
		if(cnt[1].count(it.first))
			ans+=1LL*it.second*cnt[1][it.first];
	}
	cout<<ans<<endl;
}
