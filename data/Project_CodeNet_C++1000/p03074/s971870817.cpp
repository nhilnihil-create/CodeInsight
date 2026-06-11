#include<bits/stdc++.h>
using namespace std;
int main() {
	int N, K; string S;
	cin >> N >> K >> S;
	vector<int> l;
	if(S[0] == '1') l.push_back(0);
	char pre = S[0];
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		while (i + 1 < N)
		{
			if(S[i+1] == pre) {
				i++;
				cnt++;
			}
			else break;
		}
		l.push_back(cnt);
		pre = (pre == '0') ? '1' : '0';
	}
	
	int sum[l.size()+1];
	sum[0] = 0;
	for (int i = 0; i < l.size(); i++)
	{
		sum[i+1] = sum[i] + l[i];
	}
	

	int ans = sum[min((int)l.size(), 2*K)];
	for (int i = 2; i < l.size(); i+=2)
	{
		ans = max(ans, sum[min((int)l.size(), i+2*K)] - sum[i-1]);
	}
	cout << ans << endl;
	return 0;
}
