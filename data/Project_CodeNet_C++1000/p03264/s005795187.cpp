#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    int k;
    while(~scanf("%d", &k))
    {
        int even = k/2; int odd = k - even;
        printf("%d\n", odd*even);
    }
    return 0;
}
