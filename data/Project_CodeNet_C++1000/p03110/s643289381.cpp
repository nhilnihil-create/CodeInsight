#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n; cin >> n;
    double cnt = 0;
    rep(i, n){
        double u; cin >> u;
        string x; cin >> x;
        if(x=="BTC"){
            cnt += u*380000;
        }
        else{
            cnt += u;
        }
    }
    printf("%.6f\n", cnt);

}