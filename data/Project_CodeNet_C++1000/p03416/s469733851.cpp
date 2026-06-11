#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;
int pow_10(int n)
{
	int ans = 1;
	for (int i = 0; i < n; i++) 
		ans *= 10;
	return ans;
}

int reverse_int(int n)
{
	int num[5];
	int ans = 0;
	for (int i=0; i< 5; i++){
		num[i] = n %10; // num[i]はnを10で割った余り
		n /= 10; // nを10で割ることで更新
		num[i] *= pow_10(4-i);
		// cout << "num[" << i << "] = " << num[i] << '\n';
		ans += num[i];
	}
	return ans;
}

int main()
{
	int A, B;
	cin >> A >> B;
	int count = 0;

	for (int i = A; i <= B; i++) {
		if (i == reverse_int(i)) {
			count++;
			// cout << "i = " << i << '\n';
		}	
	}
	cout << count << '\n';
}