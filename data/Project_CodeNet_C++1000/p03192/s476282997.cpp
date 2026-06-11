#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string N;
	cin >> N;

	int count = 0;
	for (int i = 0; i < N.length(); i++) {
		if (N[i] == '2') {
			count++;
		}
	}

	cout << count << endl;
	
	
}
