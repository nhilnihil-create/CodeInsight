#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
  long long t;    // 補助変数
  while ( b != 0 ) {
    t = a%b; a = b; b = t;
  }
  return a;
}
int main() {
	long long n,m,ans;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	int x=gcd(n,m);
	ans=(n*m)/x;
	for(int i=0;i<x;i++){
	    if(s[(i*n)/x]!=t[(i*m)/x])ans=-1;
	}
	cout<<ans;
	return 0;
}
