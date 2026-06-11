#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	string S; cin >> S;
	string ans = "KIHBR";
	if (S.size() < 5 || S.size() >= 10) {
		cout << "NO" << endl;
	}
	else {
		int count = 0;
		int i = 0, j = 0;
		while (i < S.size()) {
			if (S[i] == ans[j] || S[i] == 'A') {
				if (j == 0 || j == 3 || j == 4 || j == 5) {
					if (S[i] == 'A') {
						count++;
						if (count >= 2) {
							cout << "NO" << endl;
							return 0;
						}
					}
				}
				else if (j == 1 || j == 2) {
					if (S[i] == 'A') {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
			else {
				cout << "NO" << endl;
				return 0;
			}
			if (S[i] == ans[j]) {
				count = 0;
				j++;
			}
			i++;
		}
		if (j < 5) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
	}
}
