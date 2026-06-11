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

	char a[4]; 
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
		if (a[i] == 'o')
			sum+= 100;

	}
	cout << 700 + sum << endl;
}

