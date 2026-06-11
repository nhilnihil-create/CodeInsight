#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string::iterator it;
	int a=0, b=0, i=0;

	for(it=s.begin();it<s.end();it++){
		if(i%2 == *it-'0')a++;
		else b++;
		i++;
	}

	cout << min(a,b) << endl;
}