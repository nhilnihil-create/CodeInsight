#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<cctype>
#define ld long double
#define ll long long int
#define ull unsigned long long int
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const long long INF=1LL<<60;


int main(void){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t,a,b,c,d;
	cin>>a>>b;
	if(a+b==15)cout<<"+"<<endl;
	else if(a*b==15)cout<<"*"<<endl;
	else cout<<"x"<<endl;
	
	
	return 0;
}