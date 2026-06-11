#include <iostream>
#include <string>

using namespace std;

void solve()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.size() - 8; ++i)
	{
		cout << S[i];
	}
	cout << endl;
}

int main()
{
	solve();
	return(0);
}