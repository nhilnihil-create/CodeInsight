#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<utility>
#include<queue>
#include<deque>
#include<tuple>
#include<stdio.h>
#include<iomanip>
#define rep(i, n) for(int i=0;i<n;i++)
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	int a, b=0;
	rep(i, n){
		cin>>a;
		v.push_back(a);
		b=max(a, b);
	}
	rep(i, v.size()){
		b=min(gcd(v[i], b), b);
	}
	cout<<b<<endl;
	return 0;
}