#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_XYZ = 1005;
ll A[MAX_XYZ],B[MAX_XYZ],C[MAX_XYZ],AB[MAX_XYZ*MAX_XYZ],ABC[MAX_XYZ*3005];

int main()
{
	ll X,Y,Z,K;
	cin >> X >> Y >> Z >> K;
	rep(i,X)
	{
		cin >> A[i];
	}
	rep(i,Y)
	{
		cin >> B[i];
	}
	rep(i,Z)
	{
		cin >> C[i];
	}
	int cnt = 0;
	rep(i,X)
	{
		rep(j,Y)
		{
			AB[cnt] = A[i] + B[j];
			cnt++;
		}
	}
	sort(AB,AB+X*Y);
	reverse(AB,AB+X*Y);
	cnt = 0;
	rep(i,min(K,X*Y))
	{
		rep(j,Z)
		{
			ABC[cnt] = AB[i] + C[j];
			cnt++;
		}
	}
	sort(ABC,ABC+cnt);
	reverse(ABC,ABC+cnt);
	rep(i,K)
	{
		cout << ABC[i] << endl;
	}
	return 0;
}