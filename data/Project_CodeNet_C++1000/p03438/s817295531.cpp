#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    ll N;
    cin >> N;

    ll a[N], b[N];

    rep(i,N) {
        cin >> a[i];
    }
    rep(i,N) {
        cin >> b[i];
    }

    ll p,n;

    ll tmp = 0;
    rep(i,N) {
        if (a[i]-b[i]>0) {
            tmp+=(a[i]-b[i]);
        }
        else {
            tmp -=(b[i]-a[i])/2;
        }
    }

    if (tmp<=0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
