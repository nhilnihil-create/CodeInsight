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
    int x; cin >> x;
    vector<int> d;

    int cnt=1;
    d.push_back(1);
    for(int i=2; i<=x; i++){
        if(i*i>x) continue;

        cnt=i*i;

        for(int j=1; j<=9;j++){
            if(cnt*i<=x){
                cnt*=i;
            }
        }
        d.push_back(cnt);
    }
    sort(d.rbegin(), d.rend());
    out(d[0]);

}