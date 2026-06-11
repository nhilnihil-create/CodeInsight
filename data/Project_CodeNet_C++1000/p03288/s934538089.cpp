#include <stdio.h>
#include <iostream>
using namespace std;

int R;
int main (){
	cin>>R;
	if (R<1200){
		cout<< "ABC";
	}else if (R<2800){
		cout<< "ARC";
	}else{
		cout<<"AGC";
	}
}