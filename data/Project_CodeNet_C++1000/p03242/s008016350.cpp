#include <bits/stdc++.h>
using namespace std;

int main() {
	int	n;
	int ans;

	cin >> n ;
	if(n==111) ans=999;
	if(n==119) ans=991;
	if(n==191) ans=919;
	if(n==199) ans=911;
	if(n==911) ans=199;
	if(n==919) ans=191;
	if(n==991) ans=119;
	if(n==999) ans=111;
	cout << ans << endl;
	return 0;
}