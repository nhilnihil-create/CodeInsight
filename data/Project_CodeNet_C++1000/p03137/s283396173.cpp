#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>arr(m);
	for(int i=0; i<m; i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	vector<int>dist;
	for(int i=1; i<arr.size(); i++){
		dist.push_back(arr[i]-arr[i-1]);
	}
	sort(dist.begin(),dist.end());
	long long ret = 0;
	int pick = m-n;
	if(pick<=0) cout<<0;
	else{
		for(int i=0; i<pick; i++){
			ret+=dist[i];
		}
		cout<<ret;
	}
}