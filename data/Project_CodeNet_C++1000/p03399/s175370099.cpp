#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	int ans = min(A, B) + min(C, D);
	cout << ans << endl;
}
