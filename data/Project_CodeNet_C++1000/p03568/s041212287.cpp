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
	int n;
	cin>>n;
	int a[n];
	ll odd=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==1){
			odd*=1;
		}
		
		if(a[i]%2==0){
			odd*=2;
		}
	}
	ll sum=pow(3,n),ans;
	ans=sum-odd;
	cout<<ans;
}