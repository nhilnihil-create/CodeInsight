#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 100;
int N;
int P[MAX_N];
int A, B;
int main(){
scanf("%d", &N);
scanf("%d%d", &A, &B);
for(int i = 0; i < N; ++i) scanf("%d", P + i);
int e = 0, m = 0, h = 0;
for(int i = 0; i < N; ++i){
if(P[i] <= A) e++;
else if(P[i] <= B) m++;
else h++;
}
int ans = min(min(e, m), h);
printf("%d\n", ans);
return 0;
}
