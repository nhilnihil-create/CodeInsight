#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

struct node{
	long long v;
	int id;
}a[100001];

int n,sz[100001],s1[100001],s2[100001];
long long s,t;
vector<int> ga[100001];
map<long long,int> num;

bool cmp(node a,node b){
	return a.v>b.v;
}

void dfs(int x,int fa,long long d){
	s+=d;
	for(int i=0;i<ga[x].size();i++)
		if(ga[x][i]!=fa)dfs(ga[x][i],x,d+1);
}

int main(){
	int i,x,y;
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> a[i].v;
		num[a[i].v]=i;
		a[i].id=i;
		sz[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<n;i++){
		x=a[i].id;
		t=a[i].v-(n-sz[x])+sz[x];
		if(!num[t] || t>=a[i].v){
			cout << -1;
			return 0;
		}
		y=num[t];
		s1[i]=x;
		s2[i]=y;
		sz[y]+=sz[x];
		ga[x].push_back(y);
		ga[y].push_back(x);
	}
	dfs(a[n].id,0,0);
	if(s!=a[n].v){
		cout << -1;
		return 0;
	}
	for(i=1;i<n;i++)
		cout << s1[i] << ' ' << s2[i] << endl;
	return 0;
}