#include<cstdio>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n+m==15)printf("+");
    else if(n*m==15)printf("*");
    else printf("x");
    return 0;
}