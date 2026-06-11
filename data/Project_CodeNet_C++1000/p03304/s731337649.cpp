#include <stdio.h>
int main() {
    double n,m,d;
    scanf("%lf%lf%lf",&n,&m,&d);
    printf("%lf\n",((d)?2:1)*(m-1)*(n-d)/(n*n));
    return 0;
}
