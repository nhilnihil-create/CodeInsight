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
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> c;

    int n = min(a, b);
    for(int i=n; 1<=i; i--){
        if(a%i==0&&b%i==0){
            c.push_back(i);
        }
    }

    out(c[k-1]);
}