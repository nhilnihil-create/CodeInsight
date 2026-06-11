#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int A[100005];

int main()
{
	int N;
	cin >> N;
	A[0] = 0;
	A[N+1] = 0;
	int sum = 0;
	rep(i,N)
	{
		cin >> A[i+1];
		sum += abs(A[i+1]-A[i]);
	}
	sum += abs(A[N+1]-A[N]);
	rep(i,N)
	{
		int temp = sum;
		temp -= abs(A[i]-A[i+1]);
		temp -= abs(A[i+1]-A[i+2]);
		temp += abs(A[i]-A[i+2]);
		cout << temp << endl;
	}
	return 0;
}