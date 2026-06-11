#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int a,b,ans,mx=0;
	cin>>a>>b;
	ans=max(a+b,a-b);
	ans=max(ans,a*b);
	cout<<ans;
	return 0;
}
