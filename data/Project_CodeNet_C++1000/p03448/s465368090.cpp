#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;

void fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main()
{
	fast();

	int a, b, c, x,count=0;
	cin >> a >> b >> c >> x;
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			for (int k = 0; k <= c; k++)
			{
				if ((i * 500 )+ (j * 100 )+( k * 50) == x)
					count++;
			}
		}
	}
	cout << count << endl;
}

