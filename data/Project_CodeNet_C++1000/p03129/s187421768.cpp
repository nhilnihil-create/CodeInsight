#include<bits/stdc++.h>
using namespace std;
#define repl(i,x,n) for(long long i=(long long)(x);i<(long long)(n);i++)
#define rep(i,x,n) for(long i=long(x);i<long(n);i++)
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long x,y;
  	cin>>x>>y;
  	y*=2;
  	y--;
  	if(x>=y)
      	cout<<"YES";
  	else
      	cout<<"NO";
}