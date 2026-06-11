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
		string s;
		ll k;
		cin>>s>>k;
		if(s[0]!='1'){
			cout<<s[0];
		}
		else{
			ll count=0,i=0;
			while(s[i]=='1'){
				count++;
				i++;
			}
			if(count>=k){
				cout<<'1';
			}
			else{
				cout<<s[i];
			}
		}
	}
