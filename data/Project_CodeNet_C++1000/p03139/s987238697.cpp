#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    int mn;
    if (a + b <= n) {
        mn = 0;
    } else {
        mn = a + b - n;
    }
    cout << min(a, b) << " " << mn << endl;

    return 0;
}


