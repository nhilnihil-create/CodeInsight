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

template <typename T>
T gcd(T a, T b){ return b%a==0 ? a : gcd(b%a, a); }

template <typename T>
T lcm(T a, T b){ return (a/gcd(a, b))*b; }

int main()
{   
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n,0);
    rep(i,n)
    {
        if(s.substr(i,1)=="1")
            a[i] = 1;
        else
            a[i] = 0;
    }

    int m = n/2 + int(n%2==1);
    int kf = m;

    for(int i=m+1;i<=n;++i)
    {
        if(a[i-1]!=a[m-1]) break;
        kf = i;
    }

    int kb = m;
    for(int i=m+1;i<=n;++i)
    {
        if(a[n-i]!=a[n-m]) break;
        kb = i;
    }

    cout << min(kf,kb) << endl;
    return 0;
}