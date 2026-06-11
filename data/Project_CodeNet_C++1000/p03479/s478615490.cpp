#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    ll X,Y;
    cin >> X >> Y;
    ll ans = 0;
    ll tmp = X;
    while(tmp<=Y) {
        tmp*=2;
        ans++;
    }    
    cout << ans << endl;
}