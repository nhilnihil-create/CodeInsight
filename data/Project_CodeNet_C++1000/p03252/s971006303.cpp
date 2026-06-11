#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    string s, t;
    cin >> s >> t;

    vector<bool> used(26, false);
    vector<int> con(26, -1);

    int n = s.size();
    bool ok = true;
    REP(i, n){
        if(con[s[i]-'a'] != -1)
            s[i] = con[s[i]-'a']+'a';
        else{
            if(used[t[i]-'a']){
                ok = false;
                break;
            }
            else{
                used[t[i]-'a'] = true;
                con[s[i]-'a'] = t[i]-'a';
                s[i] = t[i];
            }
        }
    }
    ok &= (s == t);

    cout << (ok ? "Yes": "No") << endl;

    return 0;
}