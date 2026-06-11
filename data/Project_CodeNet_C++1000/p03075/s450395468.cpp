#include<iostream>
using namespace std;
int main(){
int a[5],k,m; 
bool aa=true;
for(int i=0; i<5; i++){
	cin>>a[i];
}
cin>>k;
for( int i =0; i<5 ;i++){
	for( int j =0; j<5 ;j++){
		m=a[i]-a[j];
		if(m>k){
			aa=false;
			break;
		}
	}		
}
if(aa){
	cout<<"Yay!";
}
else{
	cout<<":(";
}
}