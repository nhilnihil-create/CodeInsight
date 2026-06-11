#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int n;
    cin >> n;
    multiset<string> store;
    char e;
    rep(i, n){
        string s;
        cin >> s;
        store.emplace(s);
        if(i == 0) {
            e = s.back();
            continue;
        }
        if(e != s.front() || store.count(s)>1){
            cout << "No" <<endl; return 0;
        }
        e = s.back();
    }
    cout << "Yes" <<endl;
    return 0;
}