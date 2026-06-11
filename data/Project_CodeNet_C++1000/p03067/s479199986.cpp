#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, C ;
	cin >> A >> B >> C;
	if (B > A)
	{
		if (C < B && C >A) cout << "Yes";
		else cout << "No";
	}
	else
	{
		if (C > B && C <A ) cout << "Yes";
		else cout << "No";
	}
	return 0;
}
