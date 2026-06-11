#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> 
#include <string>

using namespace std;

int main() {
	string s;
	cin >>s;
	int w;
	cin >>w;
	for (int i = 0; i < s.length(); i+=w)
	{
		cout << s.at(i);

	}
}