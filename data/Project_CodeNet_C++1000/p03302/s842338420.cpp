#include <bits/stdc++.h>
using namespace std;

int main() {
	int X,Y;cin>>X>>Y;
	char ans='x';
	if(X+Y==15)ans='+';
	else if(X*Y==15)ans='*';
	cout<<ans<<endl;
}