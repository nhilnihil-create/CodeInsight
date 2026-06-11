#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll L[100];

int main()
{
	int N;
	cin >> N;
	L[0] = 2;
	L[1] = 1;
	rep(i,N-1)
	{
		L[i+2] = L[i] + L[i+1];
	}
	cout << L[N] << endl;
	return 0;
}