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
    ll r, d, x;
    cin >> r >> d >> x;
    for (int i = 0; i < 10; i++)
    {
        x = r * x - d;
        cout << x << endl;
    }

    return 0;
}