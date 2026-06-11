#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
int main( ) {
    //freopen("A.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    rep(i,0,3){
        cin >> c;
        cout << ((c=='9')?1:9);
    }
    cout << endl;
    return 0;
}