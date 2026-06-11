#include <iostream>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	long a,b,k;
	cin >> a >> b >> k;
	for (long i = a; i <= min(b, a+k-1); i++)
		cout << i << endl;
	for (long i = max(b - k + 1, a + k); i <= b; i++)
		cout << i << endl;
	return (0);
}
