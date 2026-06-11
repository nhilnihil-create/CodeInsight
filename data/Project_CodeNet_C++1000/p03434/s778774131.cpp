#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_card_game_for_two(void) {
	int n;
	int a[110] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n,std::greater<>());

	int a_sum = 0;
	int b_sum = 0;
	for (int i = 0; i < n; i++) {
		if ((i & 0x1) == 0x0) a_sum += a[i];
		else                  b_sum += a[i];
	}
	cout << a_sum - b_sum << endl;
}

int main()
{
	b_card_game_for_two();
    return 0;
}