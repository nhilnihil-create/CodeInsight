# include "iostream"
# include "cstdio"

using namespace std;

int A,B,C;

int main(){
	scanf("%d%d%d",&A,&B,&C);
	puts(A==B && B==C?"Yes":"No");
	return 0;
}