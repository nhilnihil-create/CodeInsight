#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 100001;
int main() {
	int A,B,C,a;
	scanf("%d%d%d",&A,&B,&C);
	if(B/A>C)a=C;
	else a=B/A;
	printf("%d",a);
}
