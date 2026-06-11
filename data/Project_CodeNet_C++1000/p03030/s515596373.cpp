#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n,p; cin>>n;
	vector<tuple<string,int,int>> v;
	for(int i=1;i<=n;i++){cin>>s>>p; v.push_back(make_tuple(s,-p,i));}
	sort(v.begin(),v.end());
	for(auto& t:v) cout<<get<2>(t)<<endl;
}