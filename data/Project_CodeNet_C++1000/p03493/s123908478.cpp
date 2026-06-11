#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int S=0, a=0, b=0, c=0;
  	cin >> S;
    a = S/100;
	b = (S-a*100)/10;
	c = (S-a*100-b*10)/1;
  	cout << a+b+c << endl;
}