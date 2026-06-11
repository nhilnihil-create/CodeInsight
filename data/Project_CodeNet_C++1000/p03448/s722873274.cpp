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
int solve(int a, int b,int c,int x){
	int ans=0;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			for(int k=0;k<=c;k++){
				if(x==((i*500)+(j*100)+(k*50))){
					ans++;
				}
			}
		}
	}
	return ans;
}

int main(){	
	int a,b,c,x;
	cin>>a>>b>>c>>x;
	cout<<solve(a,b,c,x);	
}