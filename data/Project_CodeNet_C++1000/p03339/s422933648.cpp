#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <iomanip>
using namespace std;

int main(){
	int n,min=10000000,ans=0;
	string s;
	vector<pair<int,int>>a(1000000);
	vector<pair<int,int>>b(1000000);
	cin>>n>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='E'){
			a[0].first++;
		}
		else{
			a[0].second++;
		}
	}
	for(int i=1;i<s.size()+1;i++){
		a[i].first=a[i-1].first;
		a[i].second=a[i-1].second;
		b[i].first=b[i-1].first;
		b[i].second=b[i-1].second;
		if(s[i-1]=='E'){
			a[i].first--;
			b[i].first++;
		}
		else{
			a[i].second--;
			b[i].second++;
		}
	}
	for(int i=1;i<s.size()+1;i++){
		if(min>a[i].first+b[i-1].second){
			min=a[i].first+b[i-1].second;
			ans=min;
		}
		//cout<<a[i].first<<a[i].second<<b[i-1].first<<b[i-1].second<<endl;
		
	}
	cout<<ans<<endl;
	return 0;
}