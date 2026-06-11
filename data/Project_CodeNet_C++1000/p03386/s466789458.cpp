#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int a,b,k;
	cin>>a>>b>>k;
	vector<int> v;
	for(int i=0;i<k;i++){
		if(a+i>b||b-i<a) continue;
		v.push_back(a+i),v.push_back(b-i);	
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++) cout<<v[i]<<"\n";
	return 0;
}