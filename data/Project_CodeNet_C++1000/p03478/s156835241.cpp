#include <iostream>
using namespace std;


int main() {

	int count = 0, count_max = 0;
	int tmp;
	int i;

	int N, A, B;
	int sum_dig;
	int sum = 0;
	

	cin >> N;
	cin >> A;
	cin >> B;


	for ( i = 1; i <= N; i++)
	{
		tmp = i;
		sum_dig = 0;
		while (tmp > 0)
		{
			sum_dig += tmp % 10;
			tmp /= 10;
		}
		
		if (sum_dig >= A && sum_dig <= B)
		{
			sum += i;
		}
		
	}
	
		
	cout << sum << endl;
		
	
	
}