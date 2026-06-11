#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;
i64 k;
i64 a[100010];
i64 b[100010];


i64 cal(int K)
{
    i64 value = 0;
    rep(i,0,n - 1)
    {
        if(!(a[i] & ~K))
        {
            value += b[i];
        }
    }
    return value;
}

int main()
{
    cin >> n >> k;
    rep(i,0,n - 1) cin >> a[i] >> b[i];

    i64 result = cal(k);
    int MAX = log2(k) + 1;
    rep(i,0,MAX)
    {
        if(k & (1 << i))
        {
            int temp = k;
            temp = temp & ~(1 << i);
            temp = temp | ((1 << i) - 1);
            result = max(result ,cal(temp));
        }
    }
    cout << result << endl;
}
