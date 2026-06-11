#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;
 
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */
 
int main() {
    int N; cin >> N;
    bool G[N][N];
    if(N % 2 == 1) {
        rep(i, N) {
            rep(j, N) {
                G[i][j] = false;
                if(i != j && j != N - i - 2)
                    G[i][j] = true;
            }
        }
        
    }else {
        rep(i, N) {
            rep(j, N) {
                G[i][j] = false;
                if(j != i && j != N - i - 1)
                    G[i][j] = true;
            }
        }
       
    }
    int cnt = 0;
    rep(i, N) {
        rng(j, i + 1, N) {
            if(G[i][j]) ++cnt;
        }
    }
    cout << cnt << endl;
    rep(i, N) {
        rng(j, i + 1, N) {
            if(G[i][j]) cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}