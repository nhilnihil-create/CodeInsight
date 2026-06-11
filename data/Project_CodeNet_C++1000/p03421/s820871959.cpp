#include <cstdio>
#include <queue>
using namespace std;

vector<int> ans;
int main(){
	int N,A,B; scanf("%d %d %d",&N,&A,&B);
	if(N<A) return !printf("-1");
	for(int i=N-A+1;i<=N;i++) if(i>0){
		ans.push_back(i);
	}
	N-=A;
	B--;
	if(B){
		int k=(N+B-1)/B;
		int r=N%B;
		if(!r) r=B;
		if(k>A || !k) return !printf("-1");
		while(B--){
			int gap=k-(r>0 ? 0:1);
			if(!gap) return !printf("-1");
			for(int i=N-gap+1;i<=N;i++) if(i>0){
				ans.push_back(i);
			}
			N-=gap;
			r--;
		}
	}
	if(N>0) return !printf("-1");
	for(int x : ans) printf("%d ",x);
}