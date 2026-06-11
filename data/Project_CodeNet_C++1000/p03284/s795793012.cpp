#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int N, K;
    std::cin >> N >> K;
    printf("%d\n", N % K != 0);
}