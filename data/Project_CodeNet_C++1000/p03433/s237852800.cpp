#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, A, surplus;

	cin >> N >> A;
	surplus = N % 500;
	if (surplus <= A)
    {
      cout << "Yes" << endl;
    }
	else if (surplus > A)
    {
      cout << "No" << endl;
    }
	return (0);
}