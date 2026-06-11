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
#include <memory>
#include <regex>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > v(n);
    for(int i=0; i<n; ++i){
        int t, d;
        cin >> t >> d;
        v[t-1].push_back(d);
    }

    priority_queue<int> pq;
    long long sum = 0;
    int cnt = 0;
    for(int i=0; i<n; ++i){
        if(v[i].empty())
            continue;
        sort(v[i].rbegin(), v[i].rend());
        sum += v[i][0];
        ++ cnt;
        for(int j=1; j<(int)v[i].size(); ++j)
            pq.push(v[i][j]);
    }

    long long ans = 0;
    sort(v.begin(), v.end());
    for(int i=0; i<n; ++i){
        if(v[i].empty())
            continue;

        while(cnt < k){
            sum += pq.top();
            pq.pop();
            ++ cnt;
        }
        if(cnt == k){
            long long x = n - i;
            ans = max(ans, x * x + sum);
        }
        sum -= v[i][0];
        pq.push(v[i][0]);
        -- cnt;
    }
    cout << ans << endl;

    return 0;
}
