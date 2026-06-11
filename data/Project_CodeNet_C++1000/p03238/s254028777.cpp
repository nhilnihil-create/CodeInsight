#include<cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    if (n == 1) {
        puts("Hello World");
    }else{
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    
}