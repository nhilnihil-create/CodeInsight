#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> A;

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	int alice = 0, bob = 0, idx = 0;
	while(idx < N)
	{
		if (idx < N)
		{
			alice += A[idx];
			idx++;
		}
		if (idx < N)
		{
			bob += A[idx];
			idx++;
		}
	}
	cout << alice - bob << endl;
	return 0;
}