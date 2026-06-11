#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int main(){
	int n;
	cin>>n;
	vector<pair<pi,int> >arr;
	for(int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		arr.push_back(make_pair(pi(x,y),0));
	}
	for(int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		arr.push_back(make_pair(pi(x,y),1));
	}
	sort(arr.begin(),arr.end());
	int ret = 0;
	int y_coord[505]={0};
	for(int i=0; i<arr.size(); i++){
		if(arr[i].second==0) y_coord[arr[i].first.second]++;
		else{
			int y = arr[i].first.second;
			for(int j=y-1; j>=0; j--){
				if(y_coord[j]){
					ret++;
					y_coord[j]--;
					break;
				}
			}
		}
	}
	cout<<ret;
}