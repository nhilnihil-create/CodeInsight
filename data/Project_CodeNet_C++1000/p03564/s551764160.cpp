#include<cstdint>
#include<limits>
#include<cstdbool>
#include<cmath>
#include<iostream>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<sstream>
#include<algorithm>

int main(){
	int n,k;
	std::cin>>n>>k;
	int a=1;
	for(int i = 0; i< n ;++i){
		if(a<k)
			a*=2;
		else
			a+=k;
	}
	std::cout<<a;

}
