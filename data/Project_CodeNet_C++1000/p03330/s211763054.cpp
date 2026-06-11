#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<climits>
#include<string>
#include<bitset>
#include<cfloat>
#include<iomanip>
#include<numeric>

//#define int long long
#define repi(i,start,end) for(int (i)=(start),TemPNuM=(int)(end);(i)<TemPNuM;++(i))
#define rep(i,end) repi((i),0,(end))
#define rfor(x,v) for(auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fsort(v,lambda) sort(all((v)),(lambda))
#define vin(v) rep(i,(v).size())cin >> (v)[i];
#define vpin(v) rep(i,(v).size())cin>>v[i].first>>v[i].second

using namespace std;
using ll =  long long;
using pint =  pair<int,int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vpint = vector<pint>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void put_double(T a){if(cout.precision()!=12)cout<<setprecision(12);cout<<a<<endl;}
template<class T>void print(T a){cout << a << endl;}
//lambda: [](int x, int y){return x<y;}

signed main(void) {
    int n, C; cin >> n >> C;
    vvint cost(C, vint(C));
    rep(i, C) {
        rep(j, C) {
            int c; cin >> c;
            cost[i][j] = c;
        }
    }
    vvint c(n, vint(n));
    rfor(v, c) vin(v);
    vvint cnts(3, vint(C, 0));
    vvint color(3);
    rep(i, n) {
        rep(j, n) {
            color[(i + j) % 3].push_back(c[i][j]);
            cnts[(i + j) % 3][c[i][j] - 1]++;
        }
    }


    int ans = INT_MAX;
    rep(i, C) rep(j, C) if(i != j) rep(k, C) if(j != k && k != i) {
        int res = 0;
        rep(x, C) res += cnts[0][x] * cost[x][i];
        rep(x, C) res += cnts[1][x] * cost[x][j];
        rep(x, C) res += cnts[2][x] * cost[x][k];
        chmin(ans, res);
    }
    print(ans);




    return 0;
}
