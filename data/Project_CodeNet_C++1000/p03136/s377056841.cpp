#include<iostream>
#include<vector>
#include<cstdio>
#include<stdio.h>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	int n,sum = 0,maxnum = 0,curnum;
	cin >> n; 	
	for(int i = 0; i< n; ++i){
		cin >> curnum;
		maxnum = curnum > maxnum ? curnum:maxnum;
		sum += curnum;
	}
	if(sum-maxnum > maxnum)printf("Yes");
	else printf("No");
	
	return 0;
} 