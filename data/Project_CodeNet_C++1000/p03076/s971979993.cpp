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

int main() {
	ll a[5],mins=9,x,ans=0;
	for(int i=0;i<5;i++){
		cin>>a[i];
		if(a[i]%10!=0){
			mins=min(a[i]%10,mins);
		}
		if(a[i]%10==mins){
			x=i;
		}
	}	
	for(int i=0;i<5;i++){
		if(i==x){
			ans+=a[i];
		}
		else{
			a[i]=((a[i]+9)/10)*10;
			ans+=a[i];
		}
	}
	cout<<ans;
}
