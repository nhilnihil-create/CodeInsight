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
	cin>>s;
	ll a=0,b=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			a++;
		}
		if(s[i]=='0'){
			b++;
		}
	}
	cout<<2*(min(a,b));	
}