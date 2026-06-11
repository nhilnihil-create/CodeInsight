#include<iostream>
#include<vector>
using namespace std;
int n,m,ans=0;
vector<int> v[55];
vector<pair<int,int> > store;
bool used[55];
bool check(int now,int lim1,int lim2){
	used[now]=true;
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(used[i]==0){flag=1;break;
		}
	}
	if(!flag)return true;
	for(int i=0;i<(int)v[now].size();i++){
		int next=v[now][i];
		if((now==lim1&&next==lim2)||(now==lim2&&next==lim1))continue;
		if(!used[next]&&check(next,lim1,lim2))return true;
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		store.push_back(make_pair(a,b));
	}
	for(int i=0;i<m;i++){
		auto p=store[i];
		int e1=p.first,e2=p.second;
		if(!check(1,e1,e2)){
			ans++;
		}
		for(int i=0;i<55;i++)used[i]=0;
	}
	cout<<ans<<endl;
}