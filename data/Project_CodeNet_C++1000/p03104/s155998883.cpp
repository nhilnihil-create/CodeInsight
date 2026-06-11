/*
   Author : tarang
*/
#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define PI = acos(-1)
using namespace std ;
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll f(ll x){
	if(x%4 == 0){
		return x ;
	}
	else if(x%4 == 1){
		return 1 ;
	}
	else if(x%4 == 2){
		return (x+1) ;
	}
	else return 0 ;
}
int main(){
	 fastio ; 
	 ll a , b ;
	 cin >> a >> b ;
	 cout << (f(b)^f(a-1)) << endl;
}