#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define eb emplace_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define vi vector<int>
#define vii vector<vi>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
int main()
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    int cnt = 0;
    rep(i, n){
        int id;
        rep2(k, 1, 100){
            if(a[i]%(1<<k) == 0) id = k;
            else break;
        }
        if(i == 0) cnt = id;
        chmin(cnt, id);

        
    }
    cout << cnt << endl;
    return 0;
}