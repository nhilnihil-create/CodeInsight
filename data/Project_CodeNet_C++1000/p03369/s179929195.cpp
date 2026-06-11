#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	int ans = 700;
	cin >> S;
	if (S.at(0) == 'o') ans += 100;
	if (S.at(1) == 'o') ans += 100;
	if (S.at(2) == 'o') ans += 100;
	cout << ans << endl;
}
