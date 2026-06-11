#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;

int n;
ll li[N+5];

int main(){
	ll ans = 0ll;
	scanf("%d",&n);
	ll hrs = 0ll;
	for(int i=1;i<=n;i++){
		scanf("%lld",&li[i]);
		if(li[i] > hrs){
			printf("-1\n");
			return 0;
		}
		if(li[i] == 0){
			hrs = 1;
			continue;
		}
		if(li[i] == li[i-1]+1){
			ans++;
		} else {
			ans+=li[i];
			hrs = li[i];
		}
		hrs++;
//		cout << ">> " << ans << endl;
	}
	printf("%lld\n",ans);
	return 0;
}