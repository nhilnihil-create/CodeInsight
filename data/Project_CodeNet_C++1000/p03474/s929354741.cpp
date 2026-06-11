#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int A,B;
	cin >> A >> B;
	string S;
	cin >> S;
	bool flag = true;
	rep(i,S.size())
	{
		if (i != A && S[i] == '-') flag = false;
		if (i == A && S[i] != '-') flag = false;
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}