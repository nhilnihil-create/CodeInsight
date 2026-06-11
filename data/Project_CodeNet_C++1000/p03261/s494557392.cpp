#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >>N;

	vector<string> strlist;
	string str;

	cin >> str;
	strlist.push_back(str);


	for (int i = 0; i < N - 1; i++)
	{
		cin >> str;
		
		for (int n = 0; n < strlist.size(); n++)
		{
			if (strlist[n] == str)
			{
				cout << "No" << endl;

				return 0;
			}
		}

		if (strlist[strlist.size() - 1][strlist[strlist.size() - 1].size() - 1] != str[0])
		{
			cout << "No" << endl;

			return 0;
		}

		strlist.push_back(str);
	}

	cout << "Yes"<< endl;

	return 0;


}

