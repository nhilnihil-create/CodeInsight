#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	string S1,S2;
	cin >> S1 >> S2;
	if (S1[0] == S2[2] && S1[1] == S2[1] && S1[2] == S2[0]) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}