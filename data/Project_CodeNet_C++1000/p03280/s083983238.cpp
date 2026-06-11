#include <stdio.h>
#include <string>
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
using namespace std;


long long int divide(long long int h,long long w){
	if(h %2 == 0){
		return (h/2)*w;
	}
	if(w %2 == 0){
		return (w/2)*h;
	}
	
	long long int mi = min(h,w);
	long long int ma = max(h,w);
	return (ma/2)*mi;
	
}

long long int calcRes(long long int rect1,long long int rect2,long long int rect3){
	long long int ma = max(rect1,max(rect2,rect3));
	long long int mi = min(rect1,min(rect2,rect3));
	
	return ma - mi;
}

int main() {
	int h,w;
	cin >> h >> w;
	cout << (h-1)*(w-1) <<endl;
	
	return 0;
}
