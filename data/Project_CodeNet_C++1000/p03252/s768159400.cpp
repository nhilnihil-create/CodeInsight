#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,t,k="Yes",al="abcdefghijklmnpoqrstuvwxyz";
	cin >> s >> t;
	int a=s.size();
	for(int i=0;i<26;i++)
	{
		char u = al.at(i),
		     tb=' ',ta=' ',sb=' ',sa=' ';
		for(int j=0;j<a;j++)
		{
			if(s.at(j)==u)
			{
				ta = t.at(j);
				if(tb != ' '&&ta != tb)
				{
					k = "No";
				}
				tb = ta;
			}
			if(t.at(j)==u)
			{
				sa = s.at(j);
				if(sb != ' '&&sa != sb)
				{
					k = "No";
				}
				sb = sa;
			}
		}
	}
	cout << k << endl;
	return 0;
}
