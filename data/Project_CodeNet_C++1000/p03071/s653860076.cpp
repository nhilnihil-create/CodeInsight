#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,get=-1;
	cin>>a>>b;
	get=max(get,a+a-1);
	get=max(get,b+b-1);
	get=max(get,a+b);
	cout<<get<<endl;
	return 0;
}
