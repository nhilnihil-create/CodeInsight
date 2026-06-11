// 基本テンプレート
 
#include <iostream>
#include <iomanip>
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
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;
 
int cnt[26];
signed main() {
    string s; cin >> s;
    rep(i,0,s.length()) cnt[ s[i] - 'a' ]++;

    vector<pii> vec;
    queue<pii> que;
    rep(i,0,26) {
        if(cnt[i] == 0) continue;
        vec.push_back(make_pair(cnt[i], i));
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    rep(i,0,vec.size()) que.push(vec[i]);

    bool ans = true;
    int pre1 = -1, pre2 = -1;
    rep(i,0,s.length()) {
        pii cur = que.front(); que.pop();
        int num = cur.first, ch = cur.second;

        if(ch == pre1 || ch == pre2) {
            ans = false;
            break;
        }
        else {
            num--;
            if(num) que.push(make_pair(num, ch));
            pre2 = pre1;
            pre1 = ch;
        }
    }
    
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}