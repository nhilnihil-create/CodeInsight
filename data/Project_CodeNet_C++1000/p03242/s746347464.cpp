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

string n;

int main(){
	cin>>n;
	For(i,0,n.size()-1){
		if (n[i]=='1') printf("9");
		else printf("1");
	}
	return 0;
}