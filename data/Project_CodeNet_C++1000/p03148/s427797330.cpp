#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
using namespace std;
#define int long long
struct str{
	int x,y;
}st[150009];
bool cmp(str a,str b){
	return a.y>b.y;
}
map<int,int> mp;
stack<int> s;
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>st[i].x>>st[i].y;
	}
	sort(st+1,st+1+n,cmp);
	int maxn=0;
	int type=0;
	int sum=0;
	for(int i=1;i<=k;i++){
		if(!mp[st[i].x]){
			mp[st[i].x]=1;
			type++;
		}
		else
			s.push(st[i].y);
		sum+=st[i].y;
		maxn=max(maxn,type*type+sum);	
	}
	for(int i=k+1;i<=n;i++){
		if(s.empty())
			break;
		if(mp[st[i].x])
			continue;
		mp[st[i].x]=1;
		type++;
		sum-=s.top();
		s.pop();
		sum+=st[i].y;
		maxn=max(maxn,type*type+sum);	
	}
	cout<<maxn;
	return 0;
}