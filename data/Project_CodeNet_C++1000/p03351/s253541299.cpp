#include <iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,c,d,ab,bc;
	cin>>a>>b>>c>>d;
	ab=abs(a-b);
	bc=abs(b-c);
	int ac=abs(a-c);
	if(ab<=d&&bc<=d || ac<=d){
		cout<<"Yes";
	}
	else{
		cout<<"No"; 
	} 
} 
