#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    for(int i=0; i<n; ++i)
        cin >> b[i];

    int ans = 0;
    for(int i=0; i<29; ++i){
        int x = 1 << i;
        vector<int> v(n);
        for(int j=0; j<n; ++j)
            v[j] = b[j] % (x << 1);
        sort(v.begin(), v.end());

        int cnt = 0;
        for(int j=0; j<n; ++j){
            int c = a[j] % (x << 1);
            vector<int> y = {x, x << 1, (x << 1) | x};
            vector<int> index(3);
            for(int k=0; k<3; ++k)
                index[k] = lower_bound(v.begin(), v.end(), y[k] - c) - v.begin();
            cnt += (index[1] - index[0]) + (n - index[2]);
        }
        if(cnt % 2 != 0)
            ans ^= x;
    }
    cout << ans << endl;

    return 0;
}
