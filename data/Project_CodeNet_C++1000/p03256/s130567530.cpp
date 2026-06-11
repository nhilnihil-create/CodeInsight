#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>g(n);
    string s;
    cin >> s;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int>q;
    rep(i,n)q.push(i);
    vector<bool>erase(n);
    while(q.size()){
        int x = q.front();
        q.pop();
        if(erase[x])continue;
        set<char>st;
        for(int i : g[x]){
            if(!erase[i])st.insert(s[i]);
        }
        if(st.size() <= 1){
            erase[x] = true;
            for(int i : g[x]){
                if(!erase[i]){
                    q.push(i);
                }
            }
        }
    }
    rep(i,n){
        if(!erase[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
}