#include<bits/stdc++.h>

using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);

int main()
{
	fast_io;
	
	string str;
	cin >> str;
	int answer = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '+')
			answer++;
		else
			answer--;
	}
	cout << answer << endl;
	
	return 0;
}
