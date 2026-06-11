#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const ll INF=2e15;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false); 

    int a,b;
    cin >> a >> b;
    vector<vector<char>> u(50,vector<char>(100,'#'));
    vector<vector<char>> d(50,vector<char>(100,'.'));
    int r=0,c=0;
    rep(i,a-1) {
        u[r][c]='.';
        c+=2;
        if (c==100) {
            c=0;
            r+=2;
        }
    }
    r=49,c=0;
    rep(i,b-1) {
        d[r][c]='#';
        c+=2;
        if (c==100) {
            c=0;
            r-=2;
        }
    }
    cout << 100 << ' ' << 100 << endl;
    rep(i,50) {
        rep(j,100) cout << u[i][j];
        cout << endl;
    }
    rep(i,50) {
        rep(j,100) cout << d[i][j];
        cout << endl;
    }

    return 0;
}
