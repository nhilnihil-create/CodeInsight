#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

ll n,f[100][10],p[100][11];

int main()
{
    int A,B,N;
    cin >> N >> A >> B;
    cout << min(N*A,B) << endl;
}