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
	ll a[n],mins=1000000005;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ll j=0;
		while(a[i]%2==0){
			a[i]/=2;
			j++;
		}
		mins=min(mins,j);
	}
	cout<<mins;
	
}

