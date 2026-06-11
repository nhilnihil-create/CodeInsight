#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int h,w,d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int,pi> >arr;
	cin>>h>>w>>d;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			int num;
			cin>>num;
			arr.push_back(make_pair(num-1,pi(i,j)));
		}
	}
	sort(arr.begin(),arr.end());
	vector<int>psum(arr.size(),0);
	for(int i=0; i<arr.size(); i++){
		int previ = i-d;
		if(previ<0) continue;
		psum[i]+=psum[previ];
		int x = arr[previ].second.first-arr[i].second.first;
		int y = arr[previ].second.second-arr[i].second.second;
		psum[i]+=abs(x)+abs(y);
	}	
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<psum[r-1]-psum[l-1]<<'\n';
	}
}