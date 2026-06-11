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
	int a[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	sort(a,a+3);
	if((a[2]-a[1])%2!=(a[2]-a[0])%2){
		cout<<a[2]-a[1]+((1-a[0]+a[1])/2)+1;
	}
	else{
		cout<<a[2]-a[1]+((a[1]-a[0])/2);
	}
}