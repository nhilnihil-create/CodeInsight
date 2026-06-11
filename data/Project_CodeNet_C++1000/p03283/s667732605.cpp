#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<int>> a(n,vector<int>(n,0));
    rep(i,m){
        int l,r;
        cin>>l>>r;
        l--,r--;
        a[l][r]++;
    }

    vector<vector<int>> s(n+1,vector<int>(n+1,0));
    rep(i,n){
        rep(j,n){
            s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a[i][j];
        }
    }

    while(q--){
        int p,q;
        cin>>p>>q;
        p--,q;
        int x2=q,y2=q,x1=p,y1=p;
        cout << s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1] << endl;
    }
}