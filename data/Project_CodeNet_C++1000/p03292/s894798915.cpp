#include<iostream>
using namespace std;
int main(){
	int a1,a2,a3,i,j,as=0,max=0,min=0;
	cin>>a1;
	cin>>a2;
	cin>>a3;
	if(a1>=a2){
		if(a2>=a3){
			max=a1;
			min=a3;
		}
		else if(a2<=a3){
			if(a1>=a3){
				max=a1;
				min=a2;
			}
			else if(a1<=a3){
				max=a3;
				min=a2;
			}
		}
	}
	if(a1<=a2){
		if(a1>=a3){
			max=a2;
			min=a3;
		}
		else if(a1<=a3){
			if(a2>=a3){
				max=a2;
				min=a1;
			}
			else if(a2<=a3){
				max=a3;
				min=a1;
			}
		}	
	}
as=max-min;
cout<<as;
}
