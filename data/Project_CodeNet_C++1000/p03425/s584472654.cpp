#include<bits/stdc++.h>
using namespace std;

int main(){
int N;
scanf("%d",&N);
vector<long long> A(5);
char c[5] = {'M','A','R','C','H'};
for(int i=0; i<N; i++){
	char name[100];
	scanf("%s",name);
	for(int j=0; j<5;j++){
		if(name[0]==c[j]){
			A[j]++;
			break;
		}
	}
}
long long  ans = A[0]*A[1]*(A[2]+A[3]+A[4])+(A[0]+A[1])*A[2]*(A[3]+A[4])+(A[0]+A[1]+A[2])*A[3]*A[4];
printf("%lld\n", ans);
return 0;
}
