#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#define pb push_back
#define mp make_pair
#define pie 3.141592653589793238
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1<<29;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/////////////////////////////////////////////////////////////////////
const ll mod = 1e9 + 7;
const int N = 1e6 + 9;
ll a[N];
vector <ll> v[105];
vector <ll> num;
ll modexp(ll a, ll n)
{
    ll r = 1;
    while(n){
        if(n & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return r;
}
bool cmp(const pair<double, ll> &a, const pair<double, int> &b)
{
    if(a.first == b.first){
        return a.second < b.second;
    }
    else return a.first > b.first;
}
int main()
{
    fast;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(a - b) <= d && abs(b - c) <= d){
        cout << "Yes";
        return 0;
    }
    else if(abs(a - c) <= d){
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
