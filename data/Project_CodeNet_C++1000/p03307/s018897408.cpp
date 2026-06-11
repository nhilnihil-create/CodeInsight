#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if(n&1) n *= 2;
    printf("%d\n", n);
}
