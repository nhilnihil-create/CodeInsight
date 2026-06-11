#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)

int main()
{   
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    auto itr_max = max_element(a.begin(),a.end());
    auto itr_min = min_element(a.begin(),a.end());

    cout << 2*n-1 << endl;
    if(abs(*itr_max)>=abs(*itr_min))
    {
        int max_idx = distance(a.begin(),itr_max) + 1;
        rep(i,n)
            cout << max_idx << " " << i+1 << endl;
        rep(i,n-1)
            cout << i+1 << " " << i+2 << endl;
    }
    else
    {
        int min_idx = distance(a.begin(),itr_min) + 1;        
        rep(i,n)
            cout << min_idx << " " << i+1 << endl;
        rep(i,n-1)
            cout << n-i << " " << n-i-1 << endl;
    }
    return 0;
}