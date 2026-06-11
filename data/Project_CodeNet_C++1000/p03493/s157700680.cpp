#include<iostream>
using namespace std;
int main(){
	char a[3];
	int x=0; 
	for(int i=0 ; i<3 ;i++){
		cin>>a[i];
		if(a[i]=='1'){
			x++;
		}
	}
	cout<<x;
}