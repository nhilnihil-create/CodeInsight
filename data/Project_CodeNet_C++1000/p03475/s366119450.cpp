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
    struct DATA
    {
        int c, s, f;
        DATA(int c = 0, int s = 0 ,int f = 0):c(c), s(s), f(f){}
    };
    vector<DATA> X(n);
    rep(i, n-1){
        int c, s, f;
        cin >> c >> s >> f;
        X[i].c = c;
        X[i].f = f;
        X[i].s = s;
    }
    vi cost(n, 0);
    rep(i, n-1){
        cost[i] += X[i].c + X[i].s;
        rep2(j, i+1, n-1){
            if(cost[i] < X[j].s){
                cost[i]  = X[j].s;
            }else{
                int r = cost[i]%X[j].f;
                if(r != 0){
                    int m = cost[i]/X[j].f;
                    cost[i] = X[j].f*(m+1);
                }
            }
            cost[i] += X[j].c;
        }
    }
    rep(i, n){
        cout << cost[i] << endl;
    }
    return 0;
}