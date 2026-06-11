#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N,A,B;
	cin >> N >> A >> B;
	cout << min(A*N,B) << endl;
	return 0;
}