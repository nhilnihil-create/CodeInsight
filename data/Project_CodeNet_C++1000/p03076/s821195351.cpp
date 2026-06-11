#include<iostream>
#include<cmath>
using namespace std;
int maxtime(int a)
{
	return (a+9)/10 * 10;
}
int rem(int a)
{
	return maxtime(a) - a;
}
int main()
{
	//using namespace std;
	ios_base:: sync_with_stdio(false);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int sum = maxtime(a) + maxtime(b) + maxtime(c) + maxtime(d) + maxtime(e);
	sum -= max(rem(a), max(rem(b), max(rem(c), max(rem(d), rem(e)))));
	cout << sum << endl;
	return 0;
}
	
