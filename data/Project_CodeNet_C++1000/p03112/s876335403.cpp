#include <iostream>
#include <set>
using namespace std;
set <long long> s1,s2;
int main(int argc, char** argv) {
	int a,b,q;
	cin >> a >> b >> q;
	s1.insert(-1e18),s1.insert(1e18);
	s2.insert(-1e18),s2.insert(1e18);
	for(int i=1;i<=a;i++)
	{
		long long x;
		cin >> x;
		s1.insert(x);
	}
	for(int i=1;i<=b;i++)
	{
		long long x;
		cin >> x;
		s2.insert(x);
	}
	while(q--)
	{
		long long x;
		cin >> x;
		long long l1,l2,r1,r2;
		l1=x-(*(--s1.upper_bound(x)));
		l2=x-(*(--s2.upper_bound(x)));
		r1=(*s1.lower_bound(x))-x;
		r2=(*s2.lower_bound(x))-x;
		cout << min(max(r1,r2),min(max(l1,l2),min(min(l1,r2)*2+max(l1,r2),min(l2,r1)*2+max(l2,r1)))) << "\n";
	}
	return 0;
}