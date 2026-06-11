#include <bits/stdc++.h>
#include <numeric>

#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())

#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
#define LL long long
#define MOD 1000000007

//cout << (c)?"Yay!":":(" << endl;

// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

pair<long double, long double> hoge(long double x1, long double y1, long double x2, long double y2)
{
    long double b = (x2 * y1 - x1 * y2) / (x2 - x1);
    long double a = (y1 - b) / x1;
    return make_pair(a, b);
}

int main()
{
    int n;
    cin>>n;
    cout<<180*(n-2)<<endl;
    return 0;
}
