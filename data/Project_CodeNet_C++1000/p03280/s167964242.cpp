#include<cstdio>

using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int area = a * b - a - b + 1;
    printf("%d\n", area); 
}