#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;

	int count_R = 0;
	int count_B = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'R') {
			count_R++;
		}
		else {
			count_B++;
		}
	}

	if (count_R > count_B) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	

}



