#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int n,m;
    cin>>n>>m;
    int L, R;
    L = 1;
    R = 100010;
    rep(_, n){
        int l, r;
        cin >> l >> r;
        L = max(L, l);
        R=min(R, r);
    }
    if(R>=L)
    cout << R - L + 1 << endl;
    else
        cout << 0 << endl;
}