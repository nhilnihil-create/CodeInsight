#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef  long long ll;
int gcd(int f , int s){if(s==0)return f;else return gcd(s,f%s);}
int const N = 600005;
ll const M = 998244353;
long double const ep = .000000000000000001;

int main() {

	int a , b ;
	cin >> a >> b;
	if(a + b ==15){
		printf("+\n");
	}else if(a*b==15){
		printf("*\n");
	}else printf("x\n");
	return 0;	
}