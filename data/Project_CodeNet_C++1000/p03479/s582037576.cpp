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
    //freopen("C.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,d = 0;
    cin >> a >> b;
    while(a<=b){       
        a *= 2;
        d++;     
    }
    cout << d << endl;
    return 0;
}