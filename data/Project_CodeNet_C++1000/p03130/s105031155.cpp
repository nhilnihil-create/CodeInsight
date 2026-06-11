#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[6],cnt[5];
int main() {
	for(int i=0;i<6;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	ll mi=3,ma=0;
	for(int i=1;i<=4;i++){
		ma=max(ma,cnt[i]);
		mi=min(mi,cnt[i]);
	}
	cout<<((ma==3||mi==0)?"NO":"YES")<<endl;
	return 0;
}