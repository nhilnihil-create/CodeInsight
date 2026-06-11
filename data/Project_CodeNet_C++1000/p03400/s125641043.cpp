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
	int n,d,x;
	cin>>n>>d>>x;
	int a[n],sum=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int m=1;
		while(m<=d){
			if(m+a[i]<=d){
				m+=a[i];
				sum++;
			}
			else{
				m+=a[i];
			}
		}
	}
	cout<<sum+x;
}

