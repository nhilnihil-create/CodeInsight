#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
//#define int  long long 
using namespace std;
int k;
string s;
set<string> st;
string gt[25000];
/*bool cmp(string a, string b)
{
	int len1 = a.size(), len2 = b.size();
	for (int i = 0; i < min(len1, len2); i++)
	{
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
	}
	if (len1 > len2) return true;
	return false;
}*/
signed main()
{
//	string a = "a", b = "aa";
//	cout << (a > b) << endl;
	while (cin >> s)
	{
		scanf("%d", &k);
		st.clear();
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				if (i + j <= len)
					st.insert(s.substr(i, j));
			}
		}
		set<string>::iterator it = st.begin();
		for (int i = 0; it != st.end(); it++, i++)
		{
			if (i == k - 1)
			{
				cout << *it << endl;
				break;
			}
			//gt[i] = *it;
		}
		//cout << gt[k - 1] << endl;
		//sort(gt, gt + st.size(), cmp);
		//for (int i = 0; i < st.size(); i++)	cout << gt[i] << endl;
	}
}
