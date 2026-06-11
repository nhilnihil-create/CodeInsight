#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	int a,b,t;
	cin >> a >> b >> t;
	
	int sum=0;
	for(int i=1;i<=t;i++){
		if(i%a==0){
			sum+=b;
		}
	}
	cout << sum << endl;
	return 0;
}
