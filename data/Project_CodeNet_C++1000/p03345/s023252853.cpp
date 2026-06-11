#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long i64;
int A, B, C; i64 k;
int main()
{
    scanf("%d%d%d%lld", &A, &B, &C, &k);
    if(~k&1) printf("%d\n", A-B); else printf("%d\n", B-A);
    return 0;
}