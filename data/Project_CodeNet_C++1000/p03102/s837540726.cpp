#include <bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)

typedef long long ll;
using namespace std;

int main() {
	int n,m,c;
	cin>>n>>m>>c;
	vector<int> B(m);
	forn(i,m)cin>>B[i];
	int A[n][m];
	forn(i,n) forn(j,m) cin>>A[i][j];
	int cnt=0;
	forn(i,n){
		ll sum=c;
		forn(j,m){
			sum+=A[i][j]*B[j];
		}
		if(sum>0)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}