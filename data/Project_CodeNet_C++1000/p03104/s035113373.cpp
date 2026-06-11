#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <map>
#include <iomanip>
#include <stdio.h>
#include <bitset>

typedef long long LL;

constexpr long long INFLL = 1e18;

using namespace std;

LL solve(LL temp)
{
    LL ans;
    LL count;
    LL x = 0;

    count = temp / 2 + 1;
    if (temp % 2)
    {
        if (count % 2)
        {
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }
    else
    {
        count--;
        ans = temp;
        if (count % 2)
        {
            ans++;
        }
        else
        {
            //処理なし
        }
    }
    return ans;
}

int main()
{
    LL A, B;
    cin >> A >> B;

    if (A > 0)
    {
        A = solve(A - 1);
    }
    bitset<64> bsA(A);
    bitset<64> bsB(solve(B));

    // cout << bsA.to_ullong() << endl;
    // cout << bsB.to_ullong() << endl;

    cout << (bsA ^ bsB).to_ullong() << endl;

    return 0;
}