#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int M = max(a,max(b,c));
	int sum = (M-a)+(M-b)+(M-c);
	if (sum % 2 == 1) sum += 3;
	cout << sum/2 << endl;
	return 0;
}