#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<int> a(100010);//a[i] := i番目までの'AC'の個数
    a[0] = 0;
    a[1] = 0;
    rep2(i, 2, N+1)
    {
        a[i] = a[i-1];
        string t = s.substr(i-2, 2);
        //cout << i << "/" << t << endl;
        if(t == "AC")
        {
            a[i] += 1;
        }
    }
    // rep2(i, 0, N+1)
    // {
    //     cout << a[i]<< ",";
    // }
    rep(i, Q)
    {
        int l, r;
        cin >> l >> r;
        //--l;
        cout << a[r] - a[l] << endl;
    }
    return 0;
}