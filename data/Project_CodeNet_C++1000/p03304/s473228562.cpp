#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
double n, m, d;
int main(){
	scanf("%lf%lf%lf", &n, &m, &d);
	printf("%.10f\n", (d ? (n-d)*2 : n)/n/n*(m-1));
}