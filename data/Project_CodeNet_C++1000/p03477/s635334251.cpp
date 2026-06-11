#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int A,B,C,D;
	cin >> A >> B >> C >> D;
	if ((A+B) > (C+D))
	{
		cout << "Left" <<  endl;
	}
	else if ((A+B) == (C+D))
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "Right" << endl;
	}
	return 0;
}