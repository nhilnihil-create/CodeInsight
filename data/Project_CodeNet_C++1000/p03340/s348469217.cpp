#include <cstdio>
using namespace std;
const int N=200010;
int n,a[N];
long long s,d,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n&&(d^a[j])==(s+a[j])){
			d^=a[j];
			s+=a[j];
			j++;
		}
		ans+=j-i;
		d^=a[i];
		s-=a[i];
	}
	printf("%lld",ans);
	return 0;
}