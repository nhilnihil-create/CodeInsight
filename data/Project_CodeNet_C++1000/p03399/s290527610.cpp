#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, sum=0;
	cin >>a>>b>>c>>d;
	if(a<b) sum+=a;
	else if(b<=a) sum+=b;
	if(c<d) sum+=c;
	else sum+=d;
	cout << sum;
    return 0;
}
