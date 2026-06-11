#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;string s;
  	cin>>n>>s;
  	int r = count(s.begin(),s.end(),'R');
  	int b = n-r;
  	if(r>b) cout<<"Yes";
  	else cout<<"No";
}