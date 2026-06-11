#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 	string a;
  	cin >> a;
  	cout << 700 + (a[0] == 'o'?100:0) + (a[1] == 'o'?100:0) + (a[2] == 'o'?100:0) << endl;
	return 0; 
}