#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int c = b - a;
    c--;
    int ans = 0;
    while(c > 0){
        ans += c;
        c--;
    }
    cout << ans - a << endl;
}