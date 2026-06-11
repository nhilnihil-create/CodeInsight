#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int a,b,c,k,m,ans=0;
	cin>>a>>b>>c>>k;
	m=max(a,b);
	m=max(m,c);
	ans+=(a+b+c-m);
	m*=pow(2,k);
	ans+=m;
	cout<<ans;
	return 0;
}