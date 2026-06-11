#include <iostream>
#include <string>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int ans = 0, i = 0;
	string str;
	bool bCheck = true;

	while (bCheck) {
		if (A + i > B)
		{
			bCheck = false;
		}
		str = to_string(A + i);
		if (str[0] == str[4] && str[1] == str[3])
		{
			break;
		}
		i++;
	}

	while (bCheck) {
		if (A + i > B)
		{
			break;
		}
		ans++;
		str = to_string(A + i);
		if (str[0] == str[4] && str[1] == str[3] && str[1] == '9' && str[2] == '9')
		{
			i += 11;
		}
		else if (str[0] == str[4] && str[1] == str[3] && str[2] == '9')
		{
			i += 110;
		}
		else if (str[0] == str[4] && str[1] == str[3])
		{
			i += 100;
		}
	}

	cout << ans << endl;
	return 0;
}