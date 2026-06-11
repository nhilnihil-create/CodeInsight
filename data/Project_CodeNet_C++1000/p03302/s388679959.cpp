#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b; cin >> a >> b;
	if (a + b == 15){
		cout << '+' << endl;
	}else
	if (a * b == 15){
		cout << '*' << endl;
	}else{
		cout << 'x' << endl;
	} // end if

	return 0;
}