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
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin(),a.end());
	ll ans=0;
	for(int i=0;i<n;i++){
		if(m==0){
			break;
		}
		ans+=(min(m,a[i].second)*a[i].first);
		m-=min(m,a[i].second);
		
	}
	cout<<ans;
}