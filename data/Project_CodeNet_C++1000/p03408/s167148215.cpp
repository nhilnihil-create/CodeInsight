#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
 
int main() {
	int n, m;
	string s[105], t[105];
	int max = 0;
	int cnt=0;
	int i, j;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> t[i];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (s[i] == s[j])
			{
				cnt++;
			}
		}
		for (j = 0; j < m; j++)
		{
			if (s[i] == t[j])
			{
				cnt--;
			}
		}
		if (max < cnt)max = cnt;
		cnt = 0;
	}
	cout << max << endl;
}



/**/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main(void) {
	return 0;
}
*/