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

bool solve(int n, int a, int b, vector<int>& ans)
{
    vector<int> v(a, 1);
    v[0] = b;
    int m = n - (a + b - 1);
    if(m < 0)
        return false;

    for(int i=1; i<a; ++i){
        int x = min(b - 1, m);
        v[i] += x;
        m -= x;
    }
    if(m > 0)
        return false;

    ans.resize(n);
    for(int i=0; i<n; ++i)
        ans[i] = i + 1;

    int k = 0;
    for(int i=0; i<a; ++i){
        reverse(ans.begin() + k, ans.begin() + k + v[i]);
        k += v[i];
    }
    return true;
}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v;
    if(solve(n, a, b, v)){
        cout << v[0];
        for(unsigned i=1; i<v.size(); ++i)
            cout << ' ' << v[i];
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
