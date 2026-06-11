#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for (int i = 0; i < n; i++)
#define fr(i,n) for(int i = n-1; i>=0;i--)

int main() {
	int n,m,t;
	cin>>n>>m>>t;
	int i,j; cin>>i>>j; i--; j--;
	string s,r;
	cin>>s>>r;
	auto win = [&](int a[], int b[], int st, int mx) {
		int l = 0, r = mx-1;
		fr(i,t) {
			if (b[i]==1 && r != mx-1) r++;	
			if (b[i]==2 && l) l--;
			if (a[i]==2) r--;
			if (a[i] == 1) l++;
			if (l>r) break;
		}
		return l<=st&&st<=r;
	};
	int a[t],b[t],c[t],d[t];
	f(i,t) {
		a[i]=b[i]=c[i]=d[i]=0;		
		if (s[i] == 'L') a[i]=1;
		if (s[i] == 'R') a[i]=2;

		if (s[i] == 'U') c[i]=1;
		if (s[i] == 'D') c[i]=2;

		if (r[i] == 'L') b[i]=1;
		if (r[i] == 'R') b[i]=2;

		if (r[i] == 'U') d[i]=1;
		if (r[i] == 'D') d[i]=2;
	}
	cout << (win(a,b,j,m)&&win(c,d,i,n)?"YES":"NO") << endl;
	

	return 0;
}
