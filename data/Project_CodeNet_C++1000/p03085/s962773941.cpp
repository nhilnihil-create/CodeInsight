#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	char b;
	cin >> b;
	if(b == 'A' || b == 'T')
		cout << (b == 'A' ? 'T' : 'A') << endl;
	else
		cout << (b == 'C' ? 'G' : 'C') << endl;

	return 0;
}
