/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5;
struct PAIR{ll A,B;}seq[N+5];
bool cprPAIR(PAIR cprA,PAIR cprB){return cprA.B-cprA.A>cprB.B-cprB.A;}
int n;
ll ans,Min=ll(1e10);
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&seq[i].A,&seq[i].B),
		ans+=seq[i].A,
		Min=seq[i].A>seq[i].B? min(Min,seq[i].B):Min;
	if(Min==ll(1e10)) printf("0\n");
	else printf("%lld\n",ans-Min);
	return 0;
}