#pragma region Macros
#include <bits/stdc++.h>
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
using namespace std;
#pragma endregion
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if (A + B > C + D)
	{
		cout << "Left" << '\n';
	}
	else if (A + B < C + D)
	{
		cout << "Right" << '\n';
	}
	else
	{
		cout << "Balanced" << '\n';
	}

	return 0;
}
