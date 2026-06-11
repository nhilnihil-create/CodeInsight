#include <bits/stdc++.h>
using namespace std;
int x,y; 
int main(){
	cin>>x>>y;
	if(x+y == 15)cout<<"+";
	else if(x*y == 15)cout<<"*";
	else cout<< "x";
} 
