#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int A[3];
	cin >> A[0] >> A[1] >> A[2];
	sort(A,A+3);
	int ans=0;
	int d1=A[2]-A[1], d2=A[2]-A[0];
	ans+=d1/2+d2/2;
	if(d1%2==1 && d2%2==1) ans++;
	else if(d1%2==0 && d2%2==0);
	else ans+=2;
	cout << ans << endl;

	return 0;
}