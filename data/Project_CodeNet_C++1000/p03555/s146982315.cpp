#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[3],b[3];
	int d=0;
	for(int i=0;i<=2;++i)cin>>a[i];
	for(int i=0;i<=2;++i)cin>>b[i];
	for(int i=0;i<=2;++i){
		if(a[i]==b[2-i])++d;
	}
  if(d==3)cout<<"YES";
  else cout<<"NO";
}