#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;


int main() {
	int i;
	int count = 0;
	int A, B;
	int K;

	cin >> A >> B>> K;
	int n = min(A,B) + 1;

	while (count < K)
	{
		n--;
		if ((A%n == 0) && (B%n == 0))
		{
			count++;
		}		
	}
	
	cout << n <<endl;

}