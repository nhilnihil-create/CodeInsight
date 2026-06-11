#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char** argv) {
	double ans=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		double x;
		string s;
		cin >> x >> s;
		if(s[0]=='B') x*=380000;
		ans+=x;
	}
	printf("%.10lf",ans);
	return 0;
}