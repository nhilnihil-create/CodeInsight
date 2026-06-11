#include<bits/stdc++.h>
using namespace std;
int main() {
	int s; cin >> s;
	vector<bool> is_appeared(1001001, false);
	int a = s;
	is_appeared[a] = true;
	for (int i = 2; ; i++)
	{
		if(a % 2 == 0) a /= 2;
		else a = 3 * a + 1;
		if(is_appeared[a]) {
			cout << i << endl;
			return 0;
		}
		else is_appeared[a] = true;
	}
	
	return 0;
}
