#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll A,B;
	cin >> A >> B;
	A--;
	ll temp = 0, ansA = 0, ansB = 0;
	if ((A/2) % 2 == 1) temp = 1;
	ansA = temp ^ A;
	if (A % 2 == 1) ansA = ansA ^ (A-1);
	temp = 0;
	if ((B/2) % 2 == 1) temp = 1;
	ansB = temp ^ B;
	if (B % 2 == 1) ansB = ansB ^ (B-1);
	//cout << ansA << " " << ansB << endl;
	if (A >= 0) cout << (ansA ^ ansB) << endl;
	else cout << ansB << endl;
	return 0;
}