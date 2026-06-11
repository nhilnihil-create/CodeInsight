#include<bits/stdc++.h>
using namespace std;
int x[100000];
int main(){
	int a,b,s;
	cin>>a>>b>>s;
	for(int i=0;i<a;i++) cin>>x[i];
	int sa=abs(x[a-1]-s);
	if(a!=1) sa=max(sa,abs(x[a-2]-x[a-1]));
	cout<<sa<<endl;
    return 0;
}