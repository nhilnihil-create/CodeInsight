#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	printf("%s\n",A==B && B==C ? "Yes" : "No");
	return 0;
}