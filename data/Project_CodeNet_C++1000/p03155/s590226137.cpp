#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <stack>
#include <iomanip>
#include <climits>
#include <complex>
#include <cmath>
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ii, int> iii;

const int maxN = 5e5 + 9, maxV = 5e5, MOD = 1e9 + 7 , lg = 20, LIM = 100;

int n, h, w;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> h >> w;
    
    cout << (n - h + 1) * (n - w + 1) << '\n';
    
    
}

/*
 4
 7 2 3 4
 1
 1 4
 */
