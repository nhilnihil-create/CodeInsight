//>> OI Solution Info <<//
// Version: 2
// State: Progress
// Problem: Snuke Numbers
// ID: ---
// Time: ---
// Timeline:
//   --- ~ --- Initialize
// Review:
//   ---
//>> End <<//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define y0 y_0
#define y1 y_1
#define yn y_n
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

int getS(long long x){
	int res=0;
	while(x>0){
		res+=x%10;
		x/=10;
	}
	return res;
}

long long getNext(long long x){
	long long sig=10;
	while(true){
		long long y=x;
		y-=y%sig;
		y+=sig-1;
		if(y*getS(x)>=x*getS(y))break;
		sig*=10;
		x=y;
	}
	return x;
}

int main(){
	int k;
	long long num=1;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		printf("%lld\n",num);
		num=getNext(num+1);
	}
	return 0;
}
