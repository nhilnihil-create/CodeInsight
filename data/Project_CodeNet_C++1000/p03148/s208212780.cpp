#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100008
ll maxn,type,sum;
struct str{
	int x,y;
}st[N];
map<int,int> mp;
stack<int> s;
bool cmp(str a,str b){
	return a.y>b.y;
}
int  main(){
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>st[i].x>>st[i].y;
  sort(st+1,st+n+1,cmp);
  for(int i=1;i<=k;i++){
  	if(!mp[st[i].x]){
  		mp[st[i].x]=1;type++;
  	}
  	else s.push(st[i].y);
  	sum+=st[i].y;
  	if(maxn<type*type+sum)maxn=type*type+sum;
  }
  for(int i=k+1;i<=n;i++){
  	if(s.empty())break;
  	if(mp[st[i].x])continue;
  	mp[st[i].x]=1;
	type++;
	sum=sum-s.top();
  	s.pop();
	sum+=st[i].y;
  	if(maxn<type*type+sum)maxn=type*type+sum;
  }
  cout<<maxn;
	return 0;
}