#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int q,a,b;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		if(a==b || a+1==b) printf("%d\n",a+a-2);
		else{
			int l=1,r=1000000001;
			while(r-l>1){
				int mid=(l+r)>>1;
				if((ll)mid*mid<(ll)a*b) l=mid;
				else r=mid;
			}
			if((ll)l*(l+1)>=(ll)a*b) printf("%d\n",l+l-2);
			else printf("%d\n",l+l-1);
		}
	}
	return 0;
}