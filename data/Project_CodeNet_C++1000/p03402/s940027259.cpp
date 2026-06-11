#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
const ll MOD = 1000000007;
using namespace std;

int main(){
    cout << 100 << " " << 100 << "\n";
    char grid[100][100];
    REP(i, 50) REP(j, 100) grid[i][j] = '#';
    for(int i = 50; i < 100; ++i) REP(j, 100) grid[i][j] = '.';
    int a, b; cin >> a >> b;
    REP(i, a-1) grid[i / 50 * 2][(2*i)%100] = '.';
    REP(i, b-1) grid[i / 50 * 2 + 51][(2*i)%100] = '#';
    REP(i, 100){
        REP(j, 100) cout << grid[i][j];
        cout << "\n";
    }
    return 0;
}