#include<cstdio>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    if (n % k == 0) puts("0");
    else puts("1");
}