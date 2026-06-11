#include <iostream>
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
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();
	
	long long a,c=0,i=0;
	double  b;
	cin >> a;
	b = sqrt(a);
	c = sqrt(a);
	i = a;
	if ((b - c) == 0)
		cout << a << endl;
	else
	{
		while (true)
		{
			i--;
			b = sqrt(i);
			c = sqrt(i);
			if ((b - c) == 0)
			{
				cout << i << endl;
				return 0;
			}
		}
	}

}