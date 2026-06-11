#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

bool palindrome(string s) {
    string tmp = s;
    reverse(all(tmp));
    return s == tmp;
}

int main() {
    string s; cin >> s;
    deque<char> q;
    rep(i,s.size()) q.push_back(s[i]);
    int ans = 0;
    while (!q.empty()) {
        char front = q.front();
        char back = q.back();
        if (front == back) {
            if (q.size() != 1) {
                q.pop_front(); 
                q.pop_back();
            } else {
                q.pop_front();
            }
        } else {
            if (front != 'x' && back != 'x') {
                cout << -1 << endl;
                return 0;
            } else if (front == 'x') {
                q.push_back('x');
                ans++;
            } else if (back == 'x') {
                q.push_front('x');
                ans++;
            }
        }
    }
    cout << ans << endl;
}