# include "iostream"
# include "cstdio"

using namespace std;

const int maxm=1e2+10;

int N,Red,Blue;
char S[maxm];

int main(){
	register int i;
	scanf("%d",&N);
	scanf("%s",S+1);
	for(i=1;i<=N;i++) Red+=(S[i]=='R');
	Blue=N-Red;
	puts(Red>Blue?"Yes":"No");
	return 0;
}