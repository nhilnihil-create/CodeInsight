#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	if((b-a)&1)
		cout<<"Borys"<<endl;
	else
		cout<<"Alice"<<endl;
}
