#include<iostream>
using namespace std;
int main()
{
	int A, B, K,n,s=1;
	int G[100];
	cin >> A >> B >> K;
	if (A > B)
	{
		n = B;
	}
	else
	{
		n = A;
	}
	for (int i = 1; i <= n; i++)
	{
		if (A % i==0&&B % i==0)
		{
			G[s] = i;
			s++;
		}
	}
	if (s > K)
	{
		cout << G[s-K];
	}
}