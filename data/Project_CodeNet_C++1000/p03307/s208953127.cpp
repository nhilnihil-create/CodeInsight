#include <iostream>
#include <cstdio>
#include <cstring>
#define fre
#define DEBUG
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (n & 1 ? n * 2 : n));
}