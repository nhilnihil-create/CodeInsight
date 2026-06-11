// https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_c
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    ll K, A, B;
    cin >> K >> A >> B;
    // A + 2  回の操作でビスケットをお金に変換し、お金をビスケットB枚に変換する
    // A + 2 枚とB枚のどちらが得かで分岐
    if (B - A - 2 > 0)
    {
        ll q = max(0LL, (K - (A - 1)) / 2);
        if (q == 0)
        {
            cout << K + 1 << endl;
            return 0;
        }
        else
        {
            ll ans = (q - 1) * (B - A) + B + (K - (A - 1)) % 2;
            cout << ans << endl;
            return 0;
        }
        
    }
    else
    {
        cout << K + 1 << endl;
        return 0;
    }
    
    return 0;
}