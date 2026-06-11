#pragma GCC optimize("O3")
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
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<P> dt(n);
    for(int i=0; i<n; i++){
        int t, d; cin>>t>>d;
        t--;
        dt[i] = P(d, t);
    }
    sort(all(dt), greater<P>());

    vector<bool> ate(n, false);
    ll del = 0, kinds = 0;
    priority_queue<int, vector<int>, greater<int>> pque;
    for(int i=0; i<k; i++){
        int d, t; tie(d, t) = dt[i];
        del += d;
        if(!ate[t]){
            ate[t] = true;
            kinds++;
        }
        else{
            pque.emplace(d);
        }
    }

    ll ans = del + kinds * kinds;
    for(int i=k; i<n; i++){
        if(!pque.size()) break;

        int d, t; tie(d, t) = dt[i];
        if(ate[t]) continue;
        ate[t] = true;
        
        kinds++;
        del -= pque.top(); pque.pop();
        del += d;
        
        chmax(ans, del + kinds * kinds);
    }

    cout << ans << endl;

    return 0;
}