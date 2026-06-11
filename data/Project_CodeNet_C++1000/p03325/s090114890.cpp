#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;
int main(void){
	int N;
  	cin >>N;
    int a,num=0;
  	for(int i=0;i<N;i++){	
      	cin >>a;
        while(a%2==0){
           a=a/2;
           num++;
        }
      	//cout <<a<<' '<<endl;
    }
  	
  	cout << num<<endl;
	return 0;
}