#include<iostream>
using namespace std;

int main(){
	int age,price;
	cin>>age>>price;
	
	if(age>=13){
		cout<<price;
		
	}
	else if(age>=6 && age<=12){
		cout<<price/2;
	}
	else if(age>=0 && age<=5){
		cout<<0;
	}
  return 0;
}