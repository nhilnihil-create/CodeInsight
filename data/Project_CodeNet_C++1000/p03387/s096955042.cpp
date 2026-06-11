#include <iostream>
using namespace std;
int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	int max=a[0];
	int total = 0; int count=0;
	for (int i = 0;i < 3;i++) {
		total += a[i];
		if (max < a[i])
			max = a[i];
	}
	if ((2*max - (total - max)) % 2 == 0)
		count = (3 * max - total) / 2;
	else count = (3 * max - total) / 2 + 2;
	cout << count;
}