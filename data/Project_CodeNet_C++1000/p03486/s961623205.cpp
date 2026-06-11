#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()

{
	string a, b;
	cin >> a >> b;

	int sizea = a.size();

	int sizeb = b.size();

	bool flag = false;


	//並び替え,
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(), greater<char>());

	if (a < b) {
		flag = true;
	}
    
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}