#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int bitCount[30] = { 0, };

    for (int bit = 29; bit >= 0; bit--)
    {            
        // a[i] + b[j]의 bit번째 비트가 1이 되는 경우의 수를 구한다
        // 일단 > bit 위치는 신경쓸 필요가 없음
        // 따라서 bit+1 위치는 모두 날려준다
        for (int i = 0; i < n; i++)
            b[i] %= (1 << (bit + 1));

        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++)
        {
            int x = a[i] % (1 << (bit + 1));
            //bit 자리 두개 더해서 bit자리가 1이 되는 경우
            //0 ~ 2^(bit+2) - 2 사이 숫자중에 2^bit를 포함하는 숫자
            //합이 2^bit 이상이 되는 거, 2^(bit+1)이 되는거 두 위치를 찾아서 빼준다.
            int lo1 = lower_bound(b.begin(), b.end(), (1 << bit) - x) - b.begin();
            int hi1 = lower_bound(b.begin(), b.end(), (1 << (bit + 1)) - x) - b.begin();

            int lo2 = lower_bound(b.begin(), b.end(), (1 << (bit + 1)) + (1 << bit) - x) - b.begin();

            bitCount[bit] += hi1 - lo1;
            bitCount[bit] += n - lo2;
        }
    }

    int ans = 0;

    for (int i = 0; i < 30; i++)
    {
        if (bitCount[i] % 2 == 0)
            continue;

        ans |= (1 << i);
    }

    printf("%d\n", ans);

    return 0;
}