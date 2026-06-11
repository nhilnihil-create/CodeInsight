#include<cstdio>
using namespace std;

int n;
int a[10];
int main(){
    scanf("%d", &n);
    int l = 1, b = 1;
    for (int i=0; i<n; ++i){
        scanf("%d", a+i);
        l *= 3;
        if (a[i] % 2 == 0) b*= 2;
    }
    printf("%d\n", l - b);
    return 0;
}