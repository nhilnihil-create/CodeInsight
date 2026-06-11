#include <iostream>

using namespace std;

int main()
{
	string x;
	cin >> x;


	int wc = 0;
	int lc = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == 'o')
			wc++;
		else
			lc++;
	}

	if (wc >= 8)
	{
		cout << "YES" << endl;
	}
	else if (lc >= 8)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
	}



	return 0;	
}