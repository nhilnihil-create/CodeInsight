#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
using namespace std;

/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second

using Graph = vector<vector<int>>;

int main()
{
    ll m, k;
    cin >> m >> k;
    if (pow(2, m) <= k)
    {
        cout << -1 << endl;
        return 0;
    }
    if (m == 0)
    {
        if (k != 0)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            cout << "0 0" << endl;
            return 0;
        }
    }
    if (m == 1)
    {
        if (k == 0)
        {
            cout << "0 0 1 1" << endl;
            return 0;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<ll> vec;
    vec.push_back(k);
    for (ll i = 0; i < pow(2, m); i++)
    {
        if (i == k)
        {
            continue;
        }
        else
        {
            vec.push_back(i);
        }
    }
    for (int i = 0; i < vec.size() - 1; i++)
    {
        cout << vec[vec.size() - 1 - i] << " ";
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << k << endl;

    return 0;
}