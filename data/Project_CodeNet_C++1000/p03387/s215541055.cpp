#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {

	int count = 0, count_max = 0;
	long int tmp;
	int i, j;

	int flag = 0;
	int a[3];

	for ( i = 0; i < 3; i++)
	{
		cin >>a[i];
	}
	
	sort(a, a+3);
	
	if ((a[2] - a[0]) % 2 == 0)
	{
		tmp = (a[2] - a[0]) /2;
		a[0] += tmp*2;
		count += tmp;
	}
	else
	{
		tmp = (a[2] - a[0]) /2;
		a[0] += tmp*2;
		count += tmp;
		flag += 1;
	}

	if ((a[2] - a[1]) % 2 == 0)
	{
		tmp = (a[2] - a[1]) /2;
		a[1] += tmp*2;
		count += tmp;
	}
	else
	{
		tmp = (a[2] - a[1]) /2;
		a[1] += tmp*2;
		count += tmp;
		flag += 1;
	}
	
	if (flag == 0)
	{
		cout << count << endl;
	}
	else if (flag%2 == 0 && flag != 0)
	{
		count++;
		cout << count << endl;
	}
	else if (flag%2 == 1 && flag != 0)
	{
		count+=2;
		cout << count << endl;
	}
	
	
	
	
}