#include<bits/stdc++.h>
#define pb push_back

typedef long long ll;
using namespace std;

typedef long double ldouble;

const ll MAXN = 1e5 + 1;

int n, h, w, sum;

int main()
{
    cin >> n >> h >> w;
    cout << (n - h + 1) * (n - w + 1);
    return 0;
}
