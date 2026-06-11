#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main(){
	char n,m;
	cin>>n>>m;
	if(n>m)cout<<">";
	if(n==m)cout<<"=";
	if(n<m)cout<<"<";
	return 0;
}