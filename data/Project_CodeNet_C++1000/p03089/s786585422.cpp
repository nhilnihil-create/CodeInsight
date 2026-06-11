#include<iostream>
#include<cstdio>
using namespace std;
int n,b[105],op[105],flag;
int main(){
	ios::sync_with_stdio(false);
	int i,j,cnt;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>b[i];
	for(i=n;i;i--){
		cnt=0;
		for(j=1;j<cnt+b[i]+(bool)op[j];j++)
			cnt+=(bool)op[j];
		op[j]=b[i];
	}
	for(i=1;i<=n;i++)
		flag|=op[i]==0;
	if(flag)
		cout<<-1;
	else
		for(i=1;i<=n;i++)
			cout<<op[i]<<endl;
	return 0;
}