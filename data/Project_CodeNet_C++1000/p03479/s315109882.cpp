#include<cstdio>
using namespace std;

int main(){
    long long int x, y;

    scanf("%lld %lld", &x, &y);

    int ans = 0;

    while(x <= y){
        x *= 2;
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}