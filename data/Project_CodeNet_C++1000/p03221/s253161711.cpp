#include <stdio.h>
#include <algorithm>
int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    unsigned long long p[m],y[m];
    unsigned long long x[m];
    for(int i=0;i<m;i++){
        scanf("%lu%lu",&p[i],&y[i]);
        x[i]=(p[i]<<47)+(y[i]<<17)+i;
    }
    std::sort(x,x+m);
    int c=1;
    y[(x[0]<<47)>>47]=c;
    for(int i=1;i<m;i++){
        if(x[i]>>47==x[i-1]>>47)c++;
        else c=1;
        y[(x[i]<<47)>>47]=c;
    }
    for(int i=0;i<m;i++){
        x[i]=p[i]*1000000+y[i];
        printf("%012lu\n",x[i]);
    }
}
