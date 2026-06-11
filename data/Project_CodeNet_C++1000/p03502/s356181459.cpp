#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
char lst[Max][Max];
int ls[Max][Max];

int main()
{
	string n;
	cin >> n;
	int sum = 0, s = 0;
	for (int i = 0; i <= n.size()-1; i++)
	{
		int t = n[i] - '0';
		sum += t;
		s *= 10;
		s += t;
	}
	if (s % sum == 0)cout << "Yes";
	else cout << "No";


}