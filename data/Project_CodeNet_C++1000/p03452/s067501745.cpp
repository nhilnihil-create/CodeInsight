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
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

vector<P> path[100005];
bool used[100005];
int dis[100005];

bool check(int p,int d){
	if(used[p]){
		if(dis[p]==d)return true;
		return false;
	}
	used[p]=true;
	dis[p]=d;
	
	for(int i=0;i<path[p].size();i++){
		if(!check(path[p][i].first,d+path[p][i].second))return false;
	}
	return true;
}


int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	bool s;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b>>c;
		a--,b--;
		path[a].push_back(make_pair(b,c));
		path[b].push_back(make_pair(a,-c));
	}
	for(i=0;i<n;i++){
		if(used[i])continue;
		s=check(i,0);
		if(!s)break;
	}
	print_Yes_No(s);
}
