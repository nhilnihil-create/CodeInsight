#include<iostream>
#include<string>
using namespace std; 
int main(){
	char a[3];
	cin>>a;
	string b="abc",c;
	c="ABC";
	int x;
	for (int i=0 ; i<3 ; i++){
	for (int j=0 ;j<3; j++){
		if(a[i]==b[j] || a[i]==c[j]){
			b[j]='0';
			c[j]='0';
			x+=1;
		}
	}}
	if(x==3){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}