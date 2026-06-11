#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
  	cin>>a>>b>>c;
  	if(a>b) swap(a,b);
  	if(c>a && c<b) cout<<"Yes";
  	else cout<<"No";
}