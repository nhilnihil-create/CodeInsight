#include<bits/stdc++.h>
using namespace std;
char r[105];
int main(){
	cin>>r;
	int n=strlen(r);
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++){
			string S="";
			for(int k=0;k<i;k++)
				S+=r[k];
			for(int k=j;k<n;k++)
				S+=r[k];
			if(S.size()==7&&S=="keyence"){
				cout<<"YES";
				return 0;
			}
		}
	cout<<"NO";
	return 0;
}