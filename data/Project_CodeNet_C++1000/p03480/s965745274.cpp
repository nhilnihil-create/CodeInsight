#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define maxn 500005
using namespace std;
int main() 
{
	char s[maxn];
	cin >> s;
	int res = strlen(s);
	int a = res;
	for (int i = 0;i < strlen(s);i++) 
	{
		if (s[i] != s[i - 1])
			res = min(res, max(i, a - i));
	}
	cout << res << endl;
	return 0;
}