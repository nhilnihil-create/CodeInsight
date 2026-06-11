#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;


int main()

{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string a,b; cin >>a>>b; bool k = true;
	

	for (int i = 0; i < 3; i++) {
		if (a[2-i] != b[i]) {
			k = false; break;
		}
	}
	if (k == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;

}