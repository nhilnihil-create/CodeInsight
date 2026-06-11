#include<bits/stdc++.h>
using namespace std;

map<int,int> mps[2];


int main(void){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int t;
		cin>>t;
		mps[i%2][t]++;
	}
	vector<pair<int,int> > v1,v2;
	transform(mps[0].begin(), mps[0].end(), back_inserter(v1), [](pair<int,int> i){return pair<int,int>(i.second, i.first);});
	transform(mps[1].begin(), mps[1].end(), back_inserter(v2), [](pair<int,int> i){return pair<int,int>(i.second, i.first);});
	sort(v1.begin(), v1.end(), greater<pair<int,int> >());
	sort(v2.begin(), v2.end(), greater<pair<int,int> >());
	int r = 0;
	if(v1[0].second == v2[0].second){
		if(v1.size() > 1 && v2.size() > 1){
			r = n - max(v1[0].first + v2[1].first, v1[1].first + v2[0].first);
		}else if(v1.size() > 1){
			r = n - v1[1].first - v2[0].first;
		}else if(v2.size() > 1){
			r = n - v1[0].first - v2[1].first;
		}else{
			r = n - max(v1[0].first, v2[0].first);
		}
	}else{
		r = n - v1[0].first - v2[0].first;
	}

	cout<<r<<'\n';	

	return 0;
}
