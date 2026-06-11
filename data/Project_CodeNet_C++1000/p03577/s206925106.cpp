#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std; 
int main(){
	char a[51];
	cin>>a;
	for(int i=0;i<strlen(a)-8;i++){
		cout<<a[i];
	}
	printf("\n");
}