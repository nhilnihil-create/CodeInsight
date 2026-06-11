#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
typedef long long ll;

using namespace std;

int main(){
	int n,m,x;
	cin>>n>>m>>x;
	int a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	int maks=0,count1=0,count2=0;
	for(int i=0;i<m;i++){
		if(a[i]<x){
			count1++;
		}
		if(a[i]>x){
			count2++;
		}
	}
	maks=min(count1,count2);
	cout<<maks;
}

