#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;
int main(void){
	int D,N;
  	cin >>D>>N;
  	if(N==100)N++;
  	cout << setprecision(10)<<pow(100,D)*N<<endl;
	return 0;
}