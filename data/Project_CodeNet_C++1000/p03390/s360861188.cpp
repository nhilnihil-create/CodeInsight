#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int main() {
	int q;cin>>q;
	vector<ll> a(q),b(q);
	for(int i=0;i<q;i++){
		cin>>a[i]>>b[i];
		ll max=a[i];
		ll min=b[i];
		if(max<min){
			max=b[i];
			min=a[i];
		}
		if(max==min){
			cout<<2*(max-1)<<endl;
			continue;
		}else if(max==min+1){
			cout<<2*(min-1)<<endl;
			continue;
		}
		ll ans=2*(min-1);
		ll sq=sqrt(max*min);
		while(sq*sq<max*min)sq++;
		if(sq*sq==min*max){
			ans=2*(sq-1)-1;
			cout<<ans<<endl;
		}else{
			if(sq*(sq-1)<max*min){
			ans=2*(sq-1)-1;
			cout<<ans<<endl;
			}else{
				ans=2*(sq-2);
				cout<<ans<<endl;
			}

		}
	}
	return 0;
}
