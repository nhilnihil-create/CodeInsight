#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
	int tcase;
	ll A,B,C,D;
	scanf("%d",&tcase);
	while(tcase--){
		scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
		if(B>A || B>D) puts("No");
		else if(C>=B) puts("Yes");
		else{
			ll last=A-(A-C)/B*B-B;
			if((A-C)%B==0) last+=B;
			if(last<0) puts("No");
			else if(D==B) puts("Yes");
			else{
				ll pos=last+(B-1-last)/__gcd(B,D-B)*__gcd(B,D-B);
				if(C<pos && pos<B) puts("No");
				else puts("Yes");
			}
		}
	}
	return 0;
}