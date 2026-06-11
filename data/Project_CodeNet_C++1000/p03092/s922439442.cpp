#include <bits/stdc++.h>

using namespace std;
const int N = 5e3 + 10;
typedef long long ll;

ll a , b , f[N];
int n , p[N];
int main(){
	scanf("%d%lld%lld",&n,&a,&b);
	for (int i = 1;i <= n;i++){
		scanf("%d",p + i);
	}
	p[n + 1] = n + 1;
	memset(f , 0x3f , sizeof f);
	f[0] = 0;
	
	for (int i = 1;i <= n + 1;i++){
		int g = 0;
		for (int j = i - 1;j >= 0;j--){
			if (p[j] > p[i]){
				g++;
			}else{
				f[i] = min(f[i] , f[j] + 1ll * g * a + 1ll * (i - j - 1 - g) * b);
			}
		}
	}
	cout<<f[n + 1];
	return 0;
}