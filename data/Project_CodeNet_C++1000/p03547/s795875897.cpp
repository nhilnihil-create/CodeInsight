#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
	char x,y;
	cin>>x>>y;
	if((int)(x)==(int)(y)) cout<<"=";
	else if((int)(x)>(int)(y)) cout<<">";
	else cout<<"<";
	return 0;
}