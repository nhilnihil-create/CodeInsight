#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1() {
    string s; cin >> s;
    int cnt = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '2') {
            cnt ++;
        }
    }

    cout << cnt << endl;
}

int main()
{
    solve1();
}
