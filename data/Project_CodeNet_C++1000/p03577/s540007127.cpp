#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size()-8;i++) putchar(s[i]);
	return 0;
}