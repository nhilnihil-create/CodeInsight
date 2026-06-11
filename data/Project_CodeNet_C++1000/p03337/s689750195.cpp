#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int ans1 = A + B;
	int ans2 = A - B;
	int ans3 = A * B;

	cout << max({ ans1,ans2,ans3 }) << endl;
}