#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;

int main()
{
	string S, T;
	cin >> S >> T;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 26; i++) {
			char c = 'A';
			for (int j = 0; j < T.size(); j++) {
				if (T[j] == 'a' + i) {
					if (c == 'A') c = S[j];
					else if (c != S[j]) {
						cout << "No" << endl;
						return 0;
					}
				}
			}
		}
		swap(S, T);
	}

	cout << "Yes" << endl;
}