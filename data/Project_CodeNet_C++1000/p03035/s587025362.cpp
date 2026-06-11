
#include <bits/stdc++.h>
#include <vector>
 
using namespace std;
const double PI=3.14159265358979323846;
 
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {

	int a, b;
	cin >> a >> b;

	int ans = b;

	if (a <= 12 && a >= 6) ans /= 2;
	if (a <= 5) ans = 0;


	cout << ans << endl;
}