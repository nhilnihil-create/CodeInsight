# include "iostream"
# include "cstdio"
# include "algorithm"

using namespace std;

const int maxm=1e3+10;
const int maxn=1e4+10;

int N;
long long DP[maxn<<1];

struct thing{
	int W;
	int S;
	int V;
	# define W(x) Thing[x].W
	# define S(x) Thing[x].S
	# define V(x) Thing[x].V
}Thing[maxm];

inline bool Comp(thing x,thing y){
	return x.S+x.W<y.S+y.W;
}

int main(){
	register int i,j,Max=0;
	register long long Ans=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++) scanf("%d%d%d",&W(i),&S(i),&V(i)),Max=max(Max,S(i)+W(i));
	sort(Thing+1,Thing+1+N,Comp);
	for(i=1;i<=N;i++){
		for(j=S(i);j>=0;j--){
			DP[j+W(i)]=max(DP[j+W(i)],DP[j]+V(i));
		}
	}
	for(i=1;i<=Max;i++) Ans=max(Ans,DP[i]);
	printf("%lld",Ans);
	return 0;
}