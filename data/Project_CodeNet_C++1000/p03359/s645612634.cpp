#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int number_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    number_of_days[a] = b;
    int res = 0;
    for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= number_of_days[i]; j++) {
			res += i == j;
		}
	}
	cout << res;
    return 0;
}
