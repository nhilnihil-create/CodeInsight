#include <iostream>

using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    if(a == 2 || b == 2)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}