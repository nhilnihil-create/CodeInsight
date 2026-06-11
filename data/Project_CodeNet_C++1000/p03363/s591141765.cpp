#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const long long int MaxN=10000005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	map <lli,lli> cub;
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	lli N,i,p,q,sum=0,res=0;
	cin>>N;
	cub[0]=1;
	for(i=0;i<N;i++){
		cin>>p;
		sum+=p;
		res+=cub[sum];
		cub[sum]+=1;
	}
	cout<<res;
}