#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	sort(S.begin(), S.end());

	if (S == "abc") {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}
