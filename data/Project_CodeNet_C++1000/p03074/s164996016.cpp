#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N,K;
	cin >> N >> K;
	string S;
	cin >> S;
	vector<int> A;
	int now = 1;
	int cnt = 0;
	rep(i,S.size())
	{
		if (S[i] != '0' + now)
		{
			A.push_back(cnt);
			cnt = 1;
			now = (now+1) % 2;
		}
		else 
		{
			cnt++;
		}
	}
	if (cnt != 0) 
	{
		A.push_back(cnt);
		now = (now+1) % 2;
	}
	if (now == 1) A.push_back(0);
	/*
	rep(i,A.size())
	{
		cout << A[i] << " ";
	}
	cout << endl;
	*/
	if (2*K+1 >= A.size())
	{
		cout << N << endl;
		return 0;
	}
	int sum = 0;
	rep(i,2*K+1)
	{
		sum += A[i];
	}
	int ans = sum;
	for (int i = 0; i < A.size()-(2*K+1); i += 2)
	{
		sum = sum - A[i] - A[i+1] + A[i+(2*K+1)] + A[i+(2*K+1)+1];
		ans = max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}