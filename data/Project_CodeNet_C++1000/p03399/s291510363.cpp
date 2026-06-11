#include<cstdio>

using namespace std;

int main(){
    int a,b,c,d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    int ans = 0;
    if (a > b) ans += b;
    else ans += a;
    if (c > d) ans += d;
    else ans += c;
    printf("%d\n", ans);

}