#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, col[100003] = {}, t;
    string s;

    cin >> s;

    n = s.size();
    t = 0;
    i = 0;
    while (i < n)
    {
        if (t > 0 && col[t - 1] != s[i] - '0')
            t--;
        else
            col[t++] = s[i] - '0';
        i++;
    }

    printf("%d\n", n - t);

    return 0;
}