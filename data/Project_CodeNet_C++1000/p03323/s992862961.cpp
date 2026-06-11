/*
       Hi there <3 
──────▄▀▄─────▄▀▄
─────▄█░░▀▀▀▀▀░░█▄
─▄▄──█░░░░░░░░░░░█──▄▄
█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>
#include <cassert>
#include <unordered_set>
#include<unordered_map>
#include <random>
#include <valarray>
//#include <fstream>
#define MOD 1000000007
#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define next next239
#define prev prev239
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define ba back()
#define popcount __builtin_popcountll
#define fastIO()                 \
    {                            \
        ios::sync_with_stdio(0); \
        cin.tie(0);              \
        cout.tie(0);             \
    }
#define in(x) \
    int x;    \
    cin >> x;
#define in1(x) \
    int x;     \
    cin >> x;  \
    x--;
#define inll(x) \
    ll x;       \
    cin >> x;
#define ins(x) \
    string x;  \
    cin >> x;

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef pair<double, double> pdd;
typedef long double LD;
typedef double D;

void Solve()
{
    ll n,m;
    cin>>n>>m;
    if((n+m)>16 || n>8 || m>8 )
    {
        cout<<":("<<endl;
    }
    else
    {
        cout<<"Yay!"<<"\n";   
    }
    
}

int main()
{
    fastIO();
    int t;
    t=1;
    while (t--)
    {
        Solve();
    }
    return 0;
}