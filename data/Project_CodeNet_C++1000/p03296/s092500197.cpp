#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int bc=0,k=0;
	for(int i=0;i<n;i++)
	{
		int nc;
		cin >> nc;
		if(nc == bc)
		{
			k++;
			bc = 0;
		}
		else
		{
			bc = nc;
		}
	}
    cout << k << endl;
	return 0;
}
