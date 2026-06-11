#include <iostream>
#include <cstdio>
#include <cstring>
//#define fre
#define DEBUG
using namespace std;
int main()
{
    int k;
    scanf("%d", &k);
    int e = k / 2, o = (k & 1 ? (k + 1) / 2 : k / 2);
    printf("%d\n", e * o);
}