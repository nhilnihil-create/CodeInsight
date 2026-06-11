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

vector<int> xs;
vector<int> ys;

int table[8005][16005];

bool canMake(vector<int>& arr, int idx, int num)
{
    if (idx == arr.size())
    {
        if (num == 0)
            return true;
        else
            return false;
    }

    if (table[idx][num + 8001] != -1)
        return table[idx][num + 8001];

    int& res = table[idx][num + 8001];

    res = 0;

    //현재 위치를 +로 가냐 -로 가냐
    if (canMake(arr, idx + 1, num + arr[idx]))
        res = 1;
    else if (canMake(arr, idx + 1, num - arr[idx]))
        res = 1;

    return res == 1;
}

int main()
{
    string s;
    int x, y;

    cin >> s >> x >> y;
    s.push_back('T');

    bool xphase = true;

    int comp = 0;

    for (auto& c : s)
    {
        if (c == 'F')
            comp++;
        else
        {
            if (xphase)
                xs.push_back(comp);
            else
                ys.push_back(comp);

            xphase = !xphase;
            comp = 0;
        }
    }

    //이 조각들로 답 확인
    bool ans = false;
    memset(table, -1, sizeof(table));

    if (xs.empty())
        ans = (x == 0);
    else
        ans = canMake(xs, 1, x - xs[0]);

    memset(table, -1, sizeof(table));

    if (ys.empty())
        ans &= (y == 0);
    else
        ans &= canMake(ys, 1, y - ys[0]) || canMake(ys, 1, y + ys[0]);

    if (ans)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}