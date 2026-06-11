#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	string s;
	int m;
	cin >> s >> m;
	
	string S;
	for (unsigned int i = 0; i < (s.size() + m - 1) / m; i++)
		printf("%c", s.at(i * m ));
}