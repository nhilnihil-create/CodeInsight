#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using ll = long long;

using namespace std;

ll mod=1e9+7;

int main() {
	int n;
	cin>>n;
	vector<pair<int,int>>red(n),blue(n);
	for(int i=0;i<n;i++){
		cin>>red[i].first>>red[i].second;
	}
	for(int i=0;i<n;i++){
		cin>>blue[i].first>>blue[i].second;
	}
	sort(red.begin(),red.end());
	sort(blue.begin(),blue.end());
	int ans=0;
	for(int i=0;i<n;i++){
		int idx=-1;
		for(int j=0;j<red.size();j++){
			if(red[j].first<=blue[i].first&&red[j].second<=blue[i].second){
				if(idx==-1){
					idx=j;
				}else if(red[idx].second<=red[j].second){
					idx=j;
				}
			}
		}
		if(idx!=-1){
			//cout<<red[idx].first<<" "<<red[idx].second<<"  "<<blue[i].first<<" "<<blue[i].second<<endl;
			ans++;
			red.erase(red.begin()+idx);
		}
	}
	cout<<ans<<endl;
	return 0;
}