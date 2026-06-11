#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<char> vi;
typedef vector<vi> vii;
int main( ) {
    //freopen("A.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vii a(3, vi(3));
    rep(i, 0, 3){
        rep(j, 0, 3){
            cin >> a[i][j];
        }
    }
    cout << a[0][0] << a[1][1] << a[2][2] << endl; 
    return 0;
}