#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007
//#define ONLINE_JUDGE

vector< vector<char> > grid;
vector< vector<ll> > ans;
ll totalPaths(int H,int W){
	if(W<0 || H<0){
		return 0;
	}
	if(H==0 && W==0){
		return 1;
	}
	if(grid[H][W]=='#'){
		return 0;
	}
	
	if(ans[H][W]==-1){
		ans[H][W] = (totalPaths(H-1,W) + totalPaths(H,W-1))%MOD;
	}
	return ans[H][W];
}
int main()
{
	/*
		Jainam Shah's Code
	*/
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N,M;
	cin>>N>>M;
	grid.resize(N);
	ans.resize(N);
	for(int j=0;j<N;j++){
		for(int i=0;i<M;i++){
			char c;
			cin>>c;
			grid[j].push_back(c);
		}
	}
	for(int i=0;i<N;i++){
		ans[i].resize(M,-1);
	}
	
	cout<<(totalPaths(N-1,M-1))<<endl;
	
	//cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
}
