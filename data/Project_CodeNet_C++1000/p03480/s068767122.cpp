#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define INF 0x7fffffff
#define re register

using namespace std;

int read()
{
	register int x = 0,f = 1;register char ch;
	ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-') f = -f;ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = x * 10 + ch - 48;ch = getchar();}
	return x * f;
}

char s[1000005];

long long  k = 100000000000000;

int main()
{
	cin >> s;
	ll l = strlen(s);
	for(ll i = 1; i < l; i++)
	{
		if(s[i] != s[i - 1])
		{
			if(i > l - i)
			{
				k = min(k,i);
//				if(s[i] == '1') s[i] = '0';
//				else s[i] = '1';
			}
			else
			{
				k = min(k,l - i);
//				if(s[i] == '1') s[i] = '0';
//				else s[i] = '1';
			}
//			cout << k << endl;
		}
	}
	cout << min(k,l) << endl;
    return 0;
}
