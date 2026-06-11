#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int main()
{
    long long n;
    while(~scanf("%lld", &n))
    {
        if(n%2)
            printf("%lld\n", n*2);
        else
            printf("%lld\n", n);
    }
    return 0;
}
