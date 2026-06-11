#include<iostream>
using namespace std;

int sep(int n)
{	
	int sum=0;

	if(n % 10 == 0)
		return sum=10;	
	while(n > 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;

	cout << sep(n) << endl;
} 

