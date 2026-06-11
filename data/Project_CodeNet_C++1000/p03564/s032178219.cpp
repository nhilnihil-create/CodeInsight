#include<stdio.h>
int main(){
    int n, k;
    int a = 1;
    scanf ("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        if(a + k < 2 * a) a += k;
        else a *= 2;
    }
   printf ("%d\n", a);
   return 0;
}