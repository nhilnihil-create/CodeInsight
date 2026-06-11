#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int a, b, t;
    scanf("%d %d %d",&a, &b, &t);
    int res = 0, i = 1;;
        t += 0.5;
        while((i * a) <= t){
            res += b;
            i = i + 1;
        };
    printf("%d\n", (res > 0 ? res : 0));
    return 0;
}
