#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
#define int long long int
const int INF = 1001001001001001LL;
const int MOD = 1000000007;

int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

signed main(){
    
    string s; cin >> s;
    int pos = 15 - s.size();
    for(int i = 0; i < s.size(); i++) if(s[i] == 'o') pos++;
    if(pos >= 8) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
