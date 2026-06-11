#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	int n;
	cin >> n;
	map<int,int> mp1,mp2;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(i%2==0){
			mp1[x]++;
		}else{
			mp2[x]++;
		}
	}
	
	int mx1=-1;
	int pre1=-1;
	vector<int> v1(n/2,0);
	for(auto itr=mp1.begin();itr!=mp1.end();itr++){
		if(itr->second>=pre1){
			mx1=itr->first;
			pre1=itr->second;
		}
		v1.push_back(itr->second);
		//pre1=itr->second;
	}
	sort(v1.begin(),v1.end(),greater<int>());

	int mx2=-1;
	int pre2=-1;	
	vector<int> v2(n/2,0);
	for(auto itr=mp2.begin();itr!=mp2.end();itr++){
		if(itr->second>=pre2){
			mx2=itr->first;
			pre2=itr->second;
		}
		v2.push_back(itr->second);
		//pre2=itr->second;
	}
	sort(v2.begin(),v2.end(),greater<int>());
	
	//cout << mx1 << " " << mx2 << endl;
	
	int ans;
	if(mx1==mx2){
		ans=n-max((v1[0]+v2[1]),(v1[1]+v2[0]));
	}else{
		ans=n-(v1[0]+v2[0]);
	}
	
	cout << ans << endl;
	
	return 0;
}
