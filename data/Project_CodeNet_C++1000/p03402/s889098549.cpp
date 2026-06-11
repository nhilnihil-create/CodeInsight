#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

void solve(int a, int b, vector<string>& s)
{
    const int n = 100;

    if(a > b){
        solve(b, a, s);
        for(int y=0; y<n; ++y){
            for(int x=0; x<n; ++x){
                s[y][x] ^= '.' ^ '#';
            }
        }
        return;
    }

    s.assign(n, string(n, '.'));
    for(int i=0; i<b; ++i){
        int y = i / (n / 4) * 4;
        int x = i % (n / 4) * 4;
        for(int j=0; j<9; ++j){
            int y2 = y + j / 3;
            int x2 = x + j % 3;
            s[y2][x2] = '#';
        }
        if(a > 1){
            -- a;
            s[y+1][x+1] = '.';
        }
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<string> s;
    solve(a, b, s);

    int h = s.size();
    int w = s[0].size();
    cout << h << ' ' << w << endl;
    for(int y=0; y<h; ++y)
        cout << s[y] << endl;

    return 0;
}
