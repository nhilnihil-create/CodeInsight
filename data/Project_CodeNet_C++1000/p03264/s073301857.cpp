#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<queue>
#include<vector>
#define LL long long
#define ULL unsigned long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define itn int
#define pritnf printf
#define mp make_pair
#define pb push_back
using namespace std;

int n;

int main(){
	cin>>n;
	if (n%2){
		printf("%d",(n/2)*(n/2+1));
	}
	else{
		printf("%d",(n/2)*(n/2));
	}
	return 0;
}