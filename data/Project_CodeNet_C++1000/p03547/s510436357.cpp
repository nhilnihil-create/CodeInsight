#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char x,y;
	cin>>x>>y;
	int a,b;
	a=x;
	b=y;
	if(a<b){
		cout<<"<";
	}
	if(a>b){
		cout<<">";
	}
	if(a==b){
		cout<<"=";
	}
	return 0;
}