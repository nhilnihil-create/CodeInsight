#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
    vector<char> s(N);
	for (int i = 0; i < N; i++) {
		char s;
		cin >> s;
		if (s == 'Y') {
			cout << "Four" << endl;
			return 0;
		}
	}
	cout << "Three" << endl;
	return 0;
}