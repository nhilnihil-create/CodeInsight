#include <iostream>
using namespace std;

int main()
{
	int nn, max = 0, ans = 0;
	bool flag;
	cin >> nn;
	int hh[nn];
	for(int ii = 0;ii < nn;ii++)
	{
		cin >> hh[ii];
		if(max < hh[ii])
		{
			max = hh[ii];
		}
	}
	for(int ii = 0;ii < max;ii++)
	{
		flag = false;
		for(int jj = 0;jj < nn;jj++)
		{
			if(hh[jj] > 0 && !flag)
			{
				flag = true;
				ans++;
			}
			else if(hh[jj] <= 0 && flag)
			{
				flag = false;
			}
			hh[jj]--;
		}
	}
	cout << ans << endl;
	return 0;
}