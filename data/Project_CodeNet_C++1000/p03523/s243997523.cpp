#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	string S,T="KIHBR";
	cin >> S;
	if(S.size()>=10){
		cout << "NO";
		return 0;
	}
	for (size_t i = 0; i < S.size(); i++)
	{
		if (S.at(i) == 'A') {
			if (i != S.size() - 1 &&S.at(i+1)!='K'&& S.at(i + 1) != 'B'&& S.at(i + 1) != 'R') {
				cout << "NO";
				return 0;
			}
			S.erase(i, 1);
		}
	}
	if (S == T)cout << "YES";
	else cout << "NO";
	
}