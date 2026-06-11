#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k=0;
	string s;
	cin >> s;
	n = s.size();
	if(n>1)
	{
		for(int i=0;i<n-1;i++)
		{
			if(s.at(i)==s.at(i+1))
			{
				k++;
				if(s.at(i+1)=='1')
				{
					s.at(i+1)='0';
				}
				else
				{
					s.at(i+1)='1';
				}
			}
		}
	}
	cout << k << endl;
	return 0;
}
