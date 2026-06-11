#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define int long long
#define double long double

//main.cpp-Sample


namespace math
{
	double PI = 3.14159265359;
	int step(int n);
	int ncr(int n,int r);

	int step(int n){
		if(n<=1){
			return 1;
		}else{
			return n * step(n-1);
		}
	}
	int ncr(int n,int r){
		for(int i=1;i<r;i++){
			n *= n-i;
		}
		for(int i=1;i<r;i++){
			r *= r-1;
		}
		return n/r;
	}
}


using namespace std;
signed main (){
	int age;
	cin >> age;
	if (age == 1)
	{
		cout << "Hello World"<<endl;
	}else{
		int a,b;
		cin >> a >> b;
		cout<<a+b<<endl;
	}
	return 0;
}


