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
	const ll x=1000000007;
	int mod(ll a){
		return a%x;
	}
	int main(){
		ll n,maks=0;
		cin>>n;
		if(n<4){
			cout<<1;
		}
		else{
			int i=2;
			while(i<=n){
				int j=2;
				while(pow(i,j)<=n){
					ll z=pow(i,j);
					maks=max(maks,z);
					j++;
				}
				i++;
			}
			cout<<maks;
		}
	}