#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)

signed main(){

	lli n;
	cin>>n;
	vector<lli> a(n),b(n);
	REP(i,0,n)cin>>a[i];
	REP(i,0,n)cin>>b[i];

	sort(b.begin(),b.end());

	lli res=0;
	/*aiに対してai+biのk桁目のビットが立つ数を数え上げる*/
	for(lli digit = 29;digit>=0;digit--){
		lli bekihigh = 1<<(digit+1),bekilow = 1<<digit;
		REP(i,0,n){
			a[i] %= bekihigh;
			b[i] %= bekihigh;
		}
		sort(b.begin(),b.end());
		lli num = 0;
		REP(i,0,n){
			lli add = 0;
			if(bekilow - a[i]>=0){
				add += lower_bound(b.begin(),b.end(),bekihigh-a[i])-
						lower_bound(b.begin(),b.end(),bekilow-a[i]);
			}
			else{
				add += lower_bound(b.begin(),b.end(),bekihigh-a[i])-b.begin();
				add += lower_bound(b.begin(),b.end(),bekihigh)
						-lower_bound(b.begin(),b.end(),bekihigh+bekilow-a[i]);
			}
			num+=add;
		}
		if(num&1)res+=bekilow;
	}
	cout<<res<<endl;

	return 0;
}