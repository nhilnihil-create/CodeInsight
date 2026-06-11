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
#define long long

using namespace std;

int main() {
	int n,m,c,ans=0;
	cin>>n>>m>>c;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		int a[m],sum=0;
		for(int j=0;j<m;j++){
			cin>>a[j];
			sum+=(a[j]*b[j]);
		}
		sum+=c;
		if(sum>0){
			ans++;
		}
	}
	cout<<ans;
}

