#include <cstdio>
using namespace std;
int main()
{
    int n, i;
    while(~scanf("%d%d", &n, &i))
        printf("%d\n", n - i + 1);
}
