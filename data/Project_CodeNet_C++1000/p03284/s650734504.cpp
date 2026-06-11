#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>

using namespace std;

const int N = 1e5+7;
#define ll long long

int main(){
	int a,b;
	cin >> a >> b;
	if(a % b == 0) cout << 0;
	else cout << 1;
	return 0; 
} 