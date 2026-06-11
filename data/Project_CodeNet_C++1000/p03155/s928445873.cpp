# include "iostream"
# include "cstdio"

using namespace std;

int N,H,W;

int main(){
	scanf("%d%d%d",&N,&H,&W);
	cout<<(N-H+1)*(N-W+1);
	return 0;
}