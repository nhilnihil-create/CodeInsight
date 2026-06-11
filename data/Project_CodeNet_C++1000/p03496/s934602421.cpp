#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;

/*
0 1 -5000

0 1 -4998






任意の要素から任意の要素を足して単調増加にできるかなー
2N回以下で!

a[i]>=a[i+1]なる最小のiをkとする
このとき

ak,ak+1が非負なら足すだけで達成
akが正、ak+1が負だと、
akもak+1も負だと、ak+1をakに足すだけで達成

前処理で「全部非負」あるいは[全部非正]を達成したい
絶対値最大値のうち大きいほうを全部に足す
*/

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<pair<ll,ll> > res;

    ll m = 1e7, M = -1e7, argm = -1, argM = -1;
    for (int i = 0; i < N; i++) {
        if (a[i] > M) {
            M = a[i]; argM = i;
        } 
        if (a[i] < m) {
            m = a[i]; argm = i;
        }
    }
    if (abs(m) > abs(M)) {
        M = m; argM = argm;
    }

    for (int i = 0; i < N; i++) {
        if (i != argM) {
            a[i] += M;
            res.push_back(make_pair(argM+1,i+1));
        }
    }

    if (a[0] >= 0) {
        for (int i = 0; i < N-1; i++) {
            if (a[i] > a[i+1]) {
                a[i+1] += a[i];
                res.push_back(make_pair(i+1,i+2));
            }
        }
    } else {
        for (int i = N-1; i >= 1; i--) {
            if (a[i-1] > a[i]) {
                a[i-1] += a[i];
                res.push_back(make_pair(i+1,i));
            }
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }


}
