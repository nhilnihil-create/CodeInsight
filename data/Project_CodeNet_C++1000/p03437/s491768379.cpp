#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}

int main(){
	ll x,y;
	cin>>x>>y;
	ll lcm=x*y/gcd(x,y);
	if(x%y==0){
		cout<<-1<<endl;
	}else{
		cout<<lcm+x<<endl;
	}
	return 0;
}
