#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;

// a b c -> a-b
// b+c a+c a+b -> b-a
// 2a+b+c 2b+a+c 2c+a+b -> a-b
// 2a+3b+3c 2b+3a+3c 2c+3a+3b -> b-a
// 

int main()
{
	LL a,b,c,k;
	cin>>a>>b>>c>>k;
	cout<<((k&1)?b-a:a-b)<<endl;
	return 0;
}