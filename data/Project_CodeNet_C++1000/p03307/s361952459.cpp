#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int ans = N;
	while (1) {
		if (ans % 2 == 0 && ans % N == 0)
		{
			cout << ans << endl;
			break;
		}
		ans++;
	}


}
