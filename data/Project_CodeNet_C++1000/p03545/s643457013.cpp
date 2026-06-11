#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	int a=n/1000;
	int b=(n/100)%10;
	int c=(n/10)%10;
	int d=n%10;
	if(a+b+c+d==7){
		cout<<a<<'+'<<b<<'+'<<c<<'+'<<d<<"=7";
	}else if(a+b+c-d==7){
		cout<<a<<'+'<<b<<'+'<<c<<'-'<<d<<"=7";
	}else if(a+b-c+d==7){
		cout<<a<<'+'<<b<<'-'<<c<<'+'<<d<<"=7";
	}else if(a-b+d+c==7){
		cout<<a<<'-'<<b<<'+'<<c<<'+'<<d<<"=7";
	}else if(a+b-d-c==7){
		cout<<a<<'+'<<b<<'-'<<c<<'-'<<d<<"=7";
	}else if(a-b-d+c==7){
		cout<<a<<'-'<<b<<'+'<<c<<'-'<<d<<"=7";
	}else if(a-b+d-c==7){
		cout<<a<<'-'<<b<<'-'<<c<<'+'<<d<<"=7";
	}else if(a-b-d-c==7){
		cout<<a<<'-'<<b<<'-'<<c<<'-'<<d<<"=7";
	}return 0;
}