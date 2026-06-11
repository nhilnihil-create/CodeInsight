#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    int H, W;
    cin >> H >> W;

    Graph<int> As(H, vint(W));
    rep(y, H) {
        rep(x, W) {
            cin >> As[y][x];
        }
    }

    int N = 0;
    vector<std::tuple<int, int, int, int>> tupleList;
    rep(y, H) {
        rep(x, W) {
            if (y != H - 1) {
                if (As[y][x] % 2 == 1) {
                    As[y][x]--;
                    As[y+1][x]++;
                    tupleList.push_back(std::make_tuple(y+1, x+1, y+2, x+1));

                    // cout << y << " " << x << " " << y+1 << " " << x << " ";
                    N++;
                }
            } else if (x != W - 1) {
                if (As[y][x] % 2 == 1) {
                    As[y][x]--;
                    As[y][x+1]++;

                    tupleList.push_back(std::make_tuple(y+1, x+1, y+1, x+2));
                    N++;
                }
            }
        }
    }
    
    cout << N << endl;
    rep(i, N) {
        cout << std::get<0>(tupleList[i]) << " " << std::get<1>(tupleList[i]) << " " << std::get<2>(tupleList[i]) << " " << std::get<3>(tupleList[i]) << endl;
    }
}