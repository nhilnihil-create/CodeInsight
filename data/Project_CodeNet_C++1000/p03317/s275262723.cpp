#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
int A[MAX_N];

int main()
{
	int N,K;
	cin >> N >> K;
	int idx1 = 0;
	rep(i,N)
	{
		cin >> A[i];
		//if (A[i] == 1) idx1 = i;
	}
	cout << (N-1 + K-1 - 1) / (K-1) << endl;
	return 0;
}