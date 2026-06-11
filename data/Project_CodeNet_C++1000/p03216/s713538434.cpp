#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int N = 1000001;
char s[N];
int n , q;
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &q);
    while (q --)
    {
        int len;
        scanf("%d", &len);
        long long ans = 0;
        long long sum = 0;
        int x = 0, y = 0;
        int r = 0;
        if (s[0] == 'M') x++;
        else
            if (s[0] == 'C' ) y ++;
        for (int i = 0; i < n ; i ++)
        {
            if (i)
            {
                if (s[i - 1] == 'M') sum -= y, x --;
                else
                    if (s[i - 1] == 'C') y --;
            }
            while (r + 1 < n && r + 1 - i + 1 <= len)
            {
                r ++;
                if (s[r] == 'M') x ++;
                else
                    if (s[r] == 'C') sum += x, y ++;
            }
            if (s[i] == 'D')
                ans += sum;
        }
        printf("%lld\n" ,ans);
    }
    return 0;
}