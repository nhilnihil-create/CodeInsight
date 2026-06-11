#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int val = 0;
	for(int i = 0; i < 4; i++) {
		char ch;
		cin >> ch;
		if(ch == '+') val++;
		else val--;
	}
	cout << val;
}
