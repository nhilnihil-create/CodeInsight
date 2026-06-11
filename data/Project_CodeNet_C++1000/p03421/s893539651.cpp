#include<bits/stdc++.h>
#define fi first
#define se second
#define lson l,mid,o<<1
#define rson mid+1,r,o<<1|1
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> P;
typedef pair<P, int> PII;
const LL INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 31;
const int NM = N * M;
const LL mod = 1e9 + 7;
const double PI=acos(-1);


int main()
{
    int n, a, b, be = 1, en;
    cin >> n >> a >> b;
    if((n + a - 1) / a > b || b > n - a + 1){
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= a; ++i){
        en = min(n - (a - i), be + b - 1);
        for(int j = en; j >= be; --j){
            printf("%d ", j);
        }
        be = en + 1;
    }
    return 0;
}
