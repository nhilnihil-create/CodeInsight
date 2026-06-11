#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

int main(){
	int a1,a2,a3;
	cin >> a1 >> a2 >> a3;
	int d1=(a1-a2)*(a1-a2);
	int d2=(a2-a3)*(a2-a3);
	int d3=(a3-a1)*(a3-a1);
	int mx=max(d1,max(d2,d3));
	
	if(mx==d1){
		cout << sqrt(d2)+sqrt(d3) << endl;
		return 0;
	}
	if(mx==d2){
		cout << sqrt(d1)+sqrt(d3) << endl;
		return 0;
	}
	if(mx==d3){
		cout << sqrt(d1)+sqrt(d2) << endl;
		return 0;
	}
	return 0;
}
