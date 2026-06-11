#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)
#define EPS 10e-8

using namespace std;
typedef pair<llong, llong> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

bool grid[100][100];

void solve(int A, int B) {
    for(int i = 0; i < 100; ++i)
        for(int j = 50; j < 100; ++j)
            grid[i][j] = true;
    
    A--, B--;

    //黒を追加
    for(int i = 0; i < 100; ++i)
        for(int j = 0; j < 50; ++j)
            if(i % 2 == 1 && j % 2 == 0) {
                if(B-- > 0)
                    grid[i][j] = true;
            }

    //白を追加
    for(int i = 0; i < 100; ++i)
        for(int j = 50; j < 100; ++j)
            if(i % 2 == 1 && j % 2 == 1) {
                if(A-- > 0)
                    grid[i][j] = false;
            }
}

int main(int argc, char **argv) {
    int A, B;
    cin >> A >> B;
    solve(A, B);

    cout << "100 100" << endl;
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j)
            cout << (grid[i][j] ? '#' : '.');
        cout << endl;
    }

}