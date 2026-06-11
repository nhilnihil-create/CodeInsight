#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> v={a,b,c};
	sort(v.begin(), v.end());
	if(v[0]!=v[1])cout<<v[0];
	if(v[1]!=v[2])cout<<v[2];
	
}