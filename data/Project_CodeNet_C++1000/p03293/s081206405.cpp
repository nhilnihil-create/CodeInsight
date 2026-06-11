#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	string S,T;
	bool ans(true);
	cin >> S;
	cin >> T;

	size_t len = S.length();
	ans = (S == T);
	for (size_t i = 1; i < len && !ans; i++)
	{
		char c = T[0];
		T.erase(T.begin());
		T.push_back(c);
		ans = (S == T);
	}
	if(ans)
		cout << "Yes\n";
	else
		cout << "No\n";

}

int main() {

//	while(1)
		func();
	return 0;
}
