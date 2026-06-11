#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong a, b;
llong wh, bl;
char mp[505][505];

int main() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) {
            mp[i][j] = '.';
        }
    }
    for (int i = 50; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            mp[i][j] = '#';
        }
    }

    for (int i = 1; i < 49; i += 2) {
        for (int j = 1; j < 99; j += 2) {
            mp[i][j] = '#';
            bl++;
        }
    }
    bl++;

    for (int i = 51; i < 99; i+= 2) {
        for (int j = 1; j < 99; j += 2) {
            mp[i][j] = '.';
            wh++;
        }
    }
    wh++;
    
    cin >> a >> b;

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) {
            if (mp[i][j] == '#' && bl > b) {
                mp[i][j] = '.';
                bl--;
            }
        }
    }
    for (int i = 50; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (mp[i][j] == '.' && wh > a) {
                mp[i][j] = '#';
                wh--;
            }
        }
    }

    cout << 100 << ' ' << 100 << endl;
    for (int i = 0; i < 100; i++) {
        cout << mp[i] << endl;
    }

    return 0;
}
