#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <utility>
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define INF 1e9
typedef long long int ll;
using namespace std;

int main()
{
    string s;
    cin >> s;

    REP(i,s.size()-8){
        cout << s[i] ;
    }

    printf("\n");

    return 0;
}