/*
Author : Devil088
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1e+7 
typedef long long ll;
typedef long l;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<l> vl;

int main(){
	string s;
	cin>>s;
	int in = 0, de = 0;
	for(auto x:s){
		if(x == '+')in++;
		else de++;
	}
	
	cout<<in-de<<"\n";
}
