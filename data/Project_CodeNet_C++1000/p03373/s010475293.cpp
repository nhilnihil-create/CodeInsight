#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	long long a,b,c;
	long long x,y;
	cin>>a>>b>>c>>x>>y;
	long long minpizza = min(x,y);
	long long money = 0;
	if(a+b>2*c){
		money+=(2*c)*minpizza;
		x-=minpizza;
		y-=minpizza;
	}
	else{
		money+=(a+b)*minpizza;
		x-=minpizza;
		y-=minpizza;
	}
	if(y){
		if(b>2*c) money+=2*c*y;
		else money+=b*y;
	}
	else{
		if(a>2*c) money+=2*c*x;
		else money+=a*x;
	}
	cout<<money;
}