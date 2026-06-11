#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_ringos_favorite_numbers(void) {
	int d, n;
	cin >> d >> n;

	int num = (int)pow(100,d);
	
	if (n == 100) n += 1;
	num *= n;

	cout << num << endl;

}

int main()
{
	b_ringos_favorite_numbers();
    return 0;
}