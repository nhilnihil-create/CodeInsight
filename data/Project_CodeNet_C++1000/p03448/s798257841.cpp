#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main( ) {
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,x,q=0;
    cin >> a >> b >> c >> x;
    rep(i, 0, a+1){
        rep(j, 0, b+1){
            rep(k, 0, c+1){
                if(500*i+100*j+50*k==x){
                    // cout << i << " " << j << " "<< k << endl;
                    q++;
                }
            }
        }
    }
    cout << q << endl;
    return 0;
}