#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	char A,B;
	cin >> A >> B;
	if (A < B) cout << "<" << endl;
	else if (A == B) cout << "=" << endl;
	else cout << ">" << endl;
	return 0;
}