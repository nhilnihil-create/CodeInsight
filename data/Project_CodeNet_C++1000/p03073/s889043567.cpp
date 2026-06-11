#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	char S;
	int count = 0;
	string S_char;
	cin >> S_char;

	if (S_char.size() == 1)
		1 + 1;
	else
	{
		for (int i = 0; i < S_char.size()-1; i++) {
			if (S_char[i] == '0') {
				if (S_char[i + 1] == '0') {
					S_char[i + 1] = '1';
					count++;
				}
			}
			else if(S_char[i] == '1')  {
				if (S_char[i + 1] == '1') {
					S_char[i + 1] = '0';
					count++;
				}
			}
		}
	}
	cout << count << endl;


	return 0;
}