#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}

vector<int> path[100005];
int used[100005];
LL num[2];

int check(int p,int q){
	int a,b,c;
	if(used[p]!=0){
		if(used[p]==q)return 0;
		return -1;
	}
	used[p]=q;
	num[(q+1)/2]++;
	for(int i=0;i<path[p].size();i++){
		a=check(path[p][i],-q);
		if(a==-1)return -1;
	}
	return 0;
}

int main(){
	LL n,m;
	int i,j,k;
	LL a,b,c;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	a=check(0,1);
	if(a==-1)b=n*(n-1)/2;
	else b=num[0]*num[1];
	b-=m;
	cout<<b<<endl;
}