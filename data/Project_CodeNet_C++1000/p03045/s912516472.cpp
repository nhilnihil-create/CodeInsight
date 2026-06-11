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

lli w[N];

lli get(lli x) {
    if(w[x] == x) {
        return x;
    }
    return w[x] = get(w[x]);
}

void merge(lli a, lli b) {

    a = get(a);
    b = get(b);
    if(a == b)
        return ;
    w[b] = a;
    return ;
}

void solve()
{

    lli n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i ++) {
        w[i] = i;
    }
    for(int i = 0; i < m ; i ++) {
        lli a, b, c;
        cin>>a>>b>>c;
        merge(a, b);
    }

    set<lli> s;

    for(int i = 1; i <= n; i ++) {
        s.insert(get(i));
    }

    cout<<s.size();

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
