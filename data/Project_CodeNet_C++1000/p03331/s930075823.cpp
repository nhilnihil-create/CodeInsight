#include <bits/stdc++.h>
using namespace std;

int sum_digits(int x){

	int sum = 0;

	while (x){

		sum += x%10;
		x /= 10;
	}
	
	return sum;

}

int main(){
	
	ios::sync_with_stdio(false);
	
	int a = 1, b, n, min = 1e5;
	
	cin >> n;
	b = n-1;

	while (a <= n/2){

		if (sum_digits(a) + sum_digits(b) < min)
			min = sum_digits(a) + sum_digits(b);
		b--;
		a++;
	}

	cout << min << endl;
	
	return 0;
}