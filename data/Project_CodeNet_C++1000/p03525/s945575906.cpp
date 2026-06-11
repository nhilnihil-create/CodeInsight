#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 10000000000000007LL
#define ll long long
using namespace std;
int cnt[13];
int used[25];
signed main(){
	int n;
	cin>>n;
	cnt[0]++;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	if( cnt[0] >= 2 || cnt[12]>=2){
		cout<<0<<endl;
		return 0;
	}
	if(cnt[0]==1){
		used[0]++;
		used[24]++;
	}
	if(cnt[12]==1){
		used[12]++;
	}
	for(int i=1;i<=11;i++){
		if(cnt[i]>=3){
			cout<<0<<endl;
			return 0;
		}
	}
	vector<int> s;
	for(int i=1;i<=11;i++){
		if(cnt[i] == 2){
			used[i]=1;
			used[24-i]=1;
		}
		else if(cnt[i] == 1){
			s.pb(i);
		}
	}
	int ss = s.size();
	int ans = -1;
	for(int i=0;i<(1<<ss);i++){
		int cur = i;
		for(int j=0;j<ss;j++){
			if(cur%2==1){
				used[s[j]]=0;
				used[24-s[j]]=1;
			}
			else{
				used[s[j]]=1;
				used[24-s[j]]=0;
			}
			cur /= 2;
		}
		int tmp=24;
		vector<int> v;
		for(int j=0;j<=24;j++){
			if(used[j]==1){
				v.pb(j);
			}
		}
		for(int j=0;j<v.size()-1;j++){
			tmp = min(tmp, v[j+1]-v[j]);
		}
		if(ans<tmp){
			ans=tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}