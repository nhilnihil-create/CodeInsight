#include <stdio.h>

int main(){
int N, K;
scanf("%d %d", &N, &K);
int operations=1;

for(int i=0;i<N;i++){
if(operations<K){
operations*=2;
}
else
operations+=K;
}

printf("%d\n", operations);
return 0;
}