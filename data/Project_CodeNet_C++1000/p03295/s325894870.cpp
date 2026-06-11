#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    
    typedef pair<int, int> P;
    vector<P> v(m);
    int s, t;
    for (int i = 0; i < m; i ++) {
        cin >> s >> t;
        v[i] = make_pair(t, s);
    }
    sort(v.begin(), v.end());

    int now = 0;
    int count = 1;
    for (int i = 1; i < m; i ++) {
        if (v[now].first <= v[i].second) {
            now = i;
            count ++;
        }
    }

    cout << count << endl;
    return 0;
}