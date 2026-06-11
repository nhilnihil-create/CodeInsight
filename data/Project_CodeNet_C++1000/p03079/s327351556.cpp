#include<cstdio>
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    return !printf("%s",a==b&&b==c?"Yes":"No");
}
