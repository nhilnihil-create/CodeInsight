#include<iostream> 
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		if((a*b)%2==0)
		cout<<"Even"<<endl;
		else
		cout<<"Odd"<<endl;
	}
	return 0;
}