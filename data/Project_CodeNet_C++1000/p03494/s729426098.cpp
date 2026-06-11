#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
#include<string>
#include <cctype>
#include <cstdlib>
#include<bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n; cin >> n;
    ll b[n];
    rep(i, n){cin >> b[i];}

    int cnt=0;
    bool flag=true;
    while(flag){
        rep(i, n){
            if(b[i]%2!=0){
                flag=false;
            }
        }
        if(flag){
            rep(i, n){
                b[i]/=2;
            }
            cnt++;
        }
    }
    out(cnt);
}