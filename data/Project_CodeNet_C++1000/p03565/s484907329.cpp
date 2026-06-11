#include<bits/stdc++.h>
using namespace std;
 
const int Maxn = 52;
 
string S, T;
string res;
 
bool Restore(int pos, string &tmp)
{
	tmp = S;
	for (int i = 0; i < T.length(); i++)
		if (S[pos + i] != '?' && S[pos + i] != T[i]) return false;
		else tmp[pos + i] = T[i];
	for (int i = 0; i < tmp.length(); i++)
		if (tmp[i] == '?') tmp[i] = 'a';
	return true;
}
 
int main()
{
	cin >> S >> T;
	string tmp;
	for (int i = 0; i + T.length() <= S.length(); i++)
		if (Restore(i, tmp))
			if (res == "" || tmp < res) res = tmp;
	if (res == "") printf("UNRESTORABLE\n");
	else printf("%s\n", res.c_str());
	return 0;
}