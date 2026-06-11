#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string	sort1(string str)
{
	int i = 0, j;
	while (i < str.size() - 1)
	{
		j = i + 1;
		while (j < str.size())
		{
			if (str[i] > str[j])
			{
				char temp;
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
	return str;
}

string	sort2(string str)
{
	int i = 0, j;
	while (i < str.size() - 1)
	{
		j = i + 1;
		while (j < str.size())
		{
			if (str[i] < str[j])
			{
				char temp;
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
			j++;
		}
		i++;
	}
	return str;
}

int		main()
{
	string str1, str2;
	cin >> str1 >> str2;
	str1 = sort1(str1);
	str2 = sort2 (str2);
	if (str1 < str2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}