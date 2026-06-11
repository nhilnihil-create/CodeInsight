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

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=0;
	if(n%2==0){
		for(int i=0;i<n;i++){
			if(i%2==0){
				sum-=a[i];
			}
			else{
				sum+=a[i];
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(i%2==0){
				sum+=a[i];
			}
			else{
				sum-=a[i];
			}
		}
	}
	cout<<sum;
}

