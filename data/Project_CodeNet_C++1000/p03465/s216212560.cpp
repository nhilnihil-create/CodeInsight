#include <bits/stdc++.h>
using namespace std;
const int N=2103;
int n,a[N],S;
bitset < N*N > bt;
int main() {
	ios::sync_with_stdio(false);
	
	cin>>n;
	
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		S+=a[i];
	}
	
	sort(a+1,a+n+1);
	
	bt[0]=1;	
	for (int i=1; i<=n; i++) {
		bt|=(bt << (a[i]));
	}
	
	for (int i=(S+1)/2; i<=S; i++) 
		if (bt[i])  {
			cout<<i<<" \n";
			return 0;
		}
}