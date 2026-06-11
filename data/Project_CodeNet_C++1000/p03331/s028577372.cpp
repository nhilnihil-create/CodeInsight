#include<bits/stdc++.h>
using namespace std;

int keta_sum(int n);

int main()
{
	int n;
	cin>>n;

	int mn=1010101010;
	int t;
	for (int i=1;i<n;i++) {
		t = keta_sum(i) + keta_sum(n - i);
		mn = min(mn, t);
	}
	cout<<mn;

	return 0;
}

int keta_sum(int n)
{
	int result = 0;
	while (n != 0) {
		result += n % 10;
		n /= 10;
	}
	return result;
}
