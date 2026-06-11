#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    string s, t;
    cin >> s >> t;
    vector<int> sC(26, -1), tC(26, -1);
    rep(i, s.size()){
        int si = s[i] - 'a';
        int ti = t[i] - 'a';
        if (sC[si] != -1 || tC[ti] != -1){
            if (sC[si] != ti || tC[ti] != si){
                cout << "No" << endl;
                return 0;
            }
        }
        sC[si] = ti;
        tC[ti] = si;
    }
    cout << "Yes" << endl;
    return 0;
}