#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	string s;
	cin >> s;

	int A, B, C, D;
	A = s[0] - 0x30;
	B = s[1] - 0x30;
	C = s[2] - 0x30;
	D = s[3] - 0x30;

	int pm[2] = { 1, -1 };
	map<int, char> mp;
	mp[1] = '+';
	mp[-1] = '-';

	for (int op1 : pm) {
		for (int op2 : pm) {
			for (int op3 : pm) {
				if (A + op1 * B + op2 * C + op3 * D == 7) {
					cout << A << mp[op1] << B << mp[op2] << C << mp[op3] << D << "=" << 7 << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}