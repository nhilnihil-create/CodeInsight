#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main() {
	int N,ans=0;
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		if (i%2==1)
		{
			int tmp = i;
			int count = 0;
			for (int j = 1; j <= i; j++)
			{
				if (tmp%j==0)
				{
					count++;
				}
			}

			if (count==8)
			{
				ans++;
			}
		}
		
	}
	cout << ans << endl;
}