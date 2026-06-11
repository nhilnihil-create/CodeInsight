#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <vector>
#include <numeric>

using namespace std;



int wa(int n) {

	int result = 0;

	while (n > 0) {
		result += n % 10;
		n /= 10;
	}

	return result;


}


int main()
{
    
	int n;
	cin >> n;

	int ans = INT_MAX;

	for (int i = 1; i <= (n + 1) / 2; i++) {

		ans = min(ans, wa(i) + wa(n - i));



	}

	cout << ans << endl;



	return 0;

}


