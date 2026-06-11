#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
    auto val = table(args...);
    return vector<decltype(val)>(n, move(val));
}
const ll INF = 1e16;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;
string grid[100];
string w = "",bl = "";
int now = 0;
bool flag = 1;
void make(int a,int b){
    if (flag && a == 1){
        int c;
        if (b%50 == 0) c = b/50;
        else c = b/50+1;
        rep(i,3*c){
            grid[i+now] = w;
        }
        rep(i,c){
            rep(j,50){
                if (b == 0) break;
                grid[now+3*i+1][2*j] = '#';
                b--;
            }
        }
        now += 3*c;
        cout << now << " " << 100 << '\n';
        rep(i,now){
            PRINT(grid[i]);
        }
    }
    else if (b == 1){
        int c;
        if (a%50 == 0) c = a/50;
        else c = a/50+1;
        rep(i,3*c){
            grid[i+now] = bl;
        }
        rep(i,c){
            rep(j,50){
                if (a == 0) break;
                grid[now+3*i+1][2*j] = '.';
                a--;
            }
        }
        now += 3*c;
        cout << now << " " << 100 << '\n';
        rep(i,now){
            PRINT(grid[i]);
        }
    }
    else{
        if (flag){
            rep(i,3){
                grid[i+now] = w;
            }
            a--;
            rep(i,50){
                if (b == 1){
                    break;
                }
                grid[now+1][i*2] = '#';
                b--;
            }
            now += 3;
            flag = 0;
            make(a,b);
        }
        else{
            rep(i,3){
                grid[i+now] = bl;
            }
            b--;
            rep(i,50){
                if (a == 1){
                    break;
                }
                grid[now+1][i*2] = '.';
                a--;
            }
            now += 3;
            flag = 1;
            make(a,b);
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    rep(i,100){
        w += '.';
        bl += '#';
    }
    make(a,b);
}
