#include<iostream>
using namespace std;
int main()
{
	string s[100];
	bool flag = false, hh = false;
	int n, i, j;
	cin >> n;
	for(i = 0; i < n; i ++)
	{
		cin >> s[i];
	}
	for(i = 1; i < n; i ++)
	{
		if(s[i][0] != s[i - 1][s[i - 1].size() - 1])
		{
			flag = false;
			break;
		}
		else
		flag = true;
	}
	for(i = 1; i < n; i ++)
	{
		for(j = 0; j < i; j ++)
		{
			if(s[i] == s[j])
			{
				hh = false;
			  	break;
		    }
			else
			{
			  	hh = true;
		    } 		
		}
		if(hh == false)
		{
		    break;
		}
	}
	if(flag == true && hh == true)
		cout << "Yes";
	else
    	cout << "No";
}