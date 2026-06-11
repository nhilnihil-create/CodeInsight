#include<iostream>
using namespace std;
int a[6];
int main()
{
	int i, min = 9, f, c = 1, s = 0;
	for(i = 1; i <= 5; i ++)
	{
		cin >> a[i];
	}
	for(i = 1; i <= 5; i ++)
	{
	    f = a[i] % 10;
		if(f != 0 && f < min)
		{
		   min = f;
		   c = i;
	    }
	}
	for(i = 1; i <= 5; i ++)
	{
		if(i != c)
		{
			s = s + (a[i] + 9) / 10 * 10;
	    } 
	}
	cout << s + a[c];
	return 0;
}
