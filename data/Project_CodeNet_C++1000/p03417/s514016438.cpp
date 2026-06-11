#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) (x.begin(),x.end())
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
 
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
    ll n, m;
    cin >> n >> m;
    ll N = min(n,m), M = max(n,m);

    if (N==1 && M==1) {
        cout << 1;
    } else if (N==1) {
        cout << M-2 << '\n';
    } else {
        cout << (N-2)*(M-2)<<'\n';
    }


    return 0;
}