#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
#include <numeric>
#include <math.h>

#define user spaesk
#define lli long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<lli> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;

void solve()
{

    lli n, H;
    cin>>n>>H;
    lli a[n];
    lli b[n];
    vector<pair<lli, lli> > v, v2;
    for(int i = 0; i < n; i ++) {
        cin>>a[i]>>b[i];
        v.push_back({a[i], i});
        v2.push_back({b[i], i});
    }
    sort(v.rbegin(), v.rend());
    sort(v2.rbegin(), v2.rend());
    sort(b, b + n);
    reverse(b, b + n);
    lli ans = 0;
    for(int i = 0 ; i < n; i ++) {
        if(H <= 0)
            break ;
        if(b[i] > v[0].ff) {
            H -= b[i];
            ans ++;
        }
    }
    H = max(H, 0LL);
    ans += ceil((ld)H / v[0].ff);
    cout<<ans;
    cout<<"\n";
    return ;
}

/*
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}
