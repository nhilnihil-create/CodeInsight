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
#define pi acos(-1)
#define int long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<int> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const int ths = 1LL << 40;
const int NN = 5e3 + 6;

const int maxN = 1000007;

///constructive algorithm
/// A k A' K
///where A is a sequence of numbers from 0 to 2 ^ m - 1 except for k and A' is the sequence A in reverse order
///using that the xor from 1 upto n is 0 if n is a multiple of 4


void solve()
{

    int m, k;
    cin>>m>>k;
    if(m == 0 )  {
        if(k == 0) {
            cout<<"0 0";
        }
        else {
            cout<<-1;
        }
        return ;
    }

    if(m == 1) {
        if(k == 0) {
            cout<<"0 0 1 1";
        }
        else
            cout<<-1;
        return ;
    }

    if(k >= (1 << m)) {
        cout<<-1;
        return ;
    }

    vector<int> v;

    for(int i = 0 ; i < (1 << m); i ++) {
        if(i != k) {
            v.push_back(i);
        }
    }

    for(auto it : v) {
        cout<<it<<' ';
    }
    cout<<k<<' ';
    reverse(v.begin(), v.end());
    for(auto it : v)
        cout<<it<<' ';
    cout<<k;

    cout<<"\n";
    return ;
}

/*
*/

int32_t main()
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
