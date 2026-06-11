#include <iostream>
using namespace std;

int main() {
	string x; cin >> x;
	bool ok = 0;
	int sz = (int)x.size();
	for(int i = 0 ; i + 2 < sz ; ++i)
	{
		if(x[i] == x[i + 1] && x[i + 1] == x[i + 2])
		{ok = 1; break;}
	}
	cout << (ok ? "Yes" : "No");
	return 0;
}