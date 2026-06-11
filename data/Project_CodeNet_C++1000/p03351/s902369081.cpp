#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
	int a,b,c,d,ans=0,mx=0;
	cin>>a>>b>>c>>d;
	if(abs(a-c)<=d)ans=1;
	else if(abs(a-b)<=d&&abs(b-c)<=d)ans=1;
	if(ans)cout<<"Yes";
	else cout<<"No";
	return 0;
}
