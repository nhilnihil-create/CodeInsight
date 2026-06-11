// template.cpp

// Defines.
//#define DEBUG
#define NUMBER_OF_DIGITS 6

// Includes.
#include <bits/stdc++.h>

#ifdef DEBUG
#include <chrono>
#endif

// Usings.
using namespace std;

// Main function.
int main()
{
#ifdef DEBUG
	chrono::system_clock::time_point start, end;
	
	start = chrono::system_clock::now();
#endif
	
	// settings.
	ios::sync_with_stdio(false);
	
	//cout << fixed;
	//cout << setprecision(NUMBER_OF_DIGITS);
	
	// logic.
	string s;
	cin >> s;
	
	int max = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int counter = 0;
		for (int j = i; j < s.size(); j++)
		{
			if ((s[j] == 'A') || (s[j] == 'C') || (s[j] == 'G') || (s[j] == 'T'))
			{
				counter++;
				if (j == (s.size() - 1))
				{
					if (counter > max)
					{
						max = counter;
					}
				}
			}
			else
			{
				if (counter > max)
				{
					max = counter;
				}
				break;
			}
		}
	}
	
	cout << max << endl;

#ifdef DEBUG
	end = chrono::system_clock::now();
	
	double elapsed = chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	cout << elapsed << "[ms]" << endl;
#endif
	
	return 0;
}
