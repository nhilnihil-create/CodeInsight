#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e5+2;
vector<int> lis[N];
pair<int,int> coor[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,m,num,ans,lef;
	cin>>n>>m>>num;
	lef=0;
	ans=n;
	for(i=1;i<=num;i++){
		cin>>j>>k;
		j-=k;
		if(j>=0){
			lis[k].push_back(j);
		}
	}
	for(i=1;i<=m;i++){
		sort(lis[i].begin(),lis[i].end());
		j=0;
		while(j<lis[i].size()&&lef>=lis[i][j]){
			if(lef==lis[i][j]){
				lef++;
			}
			j++;
		}
		if(j<lis[i].size()){
			ans=min(ans,i-1+lis[i][j]);
		}
	}
	cout<<ans;
}