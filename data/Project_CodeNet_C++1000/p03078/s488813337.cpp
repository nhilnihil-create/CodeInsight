#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdarg>
#include <set>
#include <limits>
#include <iomanip>

using namespace std;
#define INF 2e9 + 9
#define MOD 1000000007
#define ALL(v) v.begin() , v.end()
#define Int int64_t
#define pll pair<Int,Int>
template<class T> using pql = priority_queue<T, vector<T>>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define ll(n) Int n; cin >> n;
#define LL(...) Int __VA_ARGS___; cin >> __VA_ARGS___;
#define OUT(...) cout << __VA_ARGS___;
#define RP(n, i, s) for(Int i = s ;i < n ;i++)
#define REP(n, i) for (Int i = 0; i < n; i++)
#define REPe(n, i) for (Int i = 1; i <= n; i++)
#define RPe(n, i, s) for (Int i = s; i <= n; i++)
#define upd_max(maxer, updater) if (maxer < updater) maxer = updater;

void ansYes(bool flag){
    if (flag) cout << "Yes" << endl; else  cout << "No" << endl;
}

void ansYES(bool flag){
    if (flag) cout << "YES" << endl; else  cout << "NO" << endl;
}

struct node {
    Int to;
    Int length;
};


vector<Int> divisor(Int n) {
    vector<Int> ret;
    for (Int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    return (ret);
}

/*
vector<vector<int>> to;
vector<int> flag;
vector<int> c;


Int dfs(int from, int mae) {
    flag[from] = 1;
    Int mini = 0;
    for (auto next : to[from]) {
        if (next == mae) continue;
        if (flag[next] == 1) {
            return -1;
        } else {
            mini = min(mini, dfs(next, from));
        }
    }
    return mini;
}*/

int dx8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int main(){
    Int x , y, z ,k;
    cin >> x >> y >> z >> k;
    vector<Int> a(x);
    vector<Int> b(y);
    vector<Int> c(z);
    REP(x,i){
        cin >> a.at(i);
    }
    REP(y,i){
        cin >> b.at(i);
    }
    REP(z,i){
        cin >> c.at(i);
    }
    sort(c.begin(),c.end(),greater<>());
    vector<Int> d;
    REP(x,i){
        REP(y,k){
            d.push_back(a.at(i) + b.at(k));
        }
    }
    sort(d.begin(),d.end(),greater<>());
    Int esize = min((Int)d.size(),(Int)3000);
    vector<Int> e(esize);
    for (int i = 0; i < esize; i++) {
        e.at(i) = d.at(i);
    }
    vector<Int> f;
    for (auto z : e){
        for (auto k : c){
            f.push_back(z + k);
        }
    }
    sort(f.begin(),f.end(),greater<>());
    for (int i = 0; i < k; i++){
        cout << f.at(i) << endl;
    }

}