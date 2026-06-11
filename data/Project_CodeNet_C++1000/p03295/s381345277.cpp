#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    ll N, M;
    cin >> N >> M;;
    vector<vector<ll>> A(M,vector<ll>(2));
    rep(i,0,M) {
        cin >> A[i][1] >> A[i][0];
    }

    sort(A.begin(),A.end());

    ll tmp = 0;

    ll ans = 0;

    rep(i,0,M) {
        if (A[i][1]>=tmp) {
            ans++;
            tmp = A[i][0];
        }

    }

    cout << ans << endl;

}



