#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

ll K;
ll ans_max = -1;
ll ans_min = INF;

int main(){
    cin >> K;
    vector<ll> A;

    rep(i,K) {
        ll a;
        cin >> a;
        A.push_back(a);
    }

    reverse(A.begin(),A.end());
    vector<ll> Bmin,Bmax;

    Bmin.push_back(2);
    Bmax.push_back(2);
    bool t = true;
    rep(i,K-1) {
        ll bmax = Bmax[i]+A[i]-1;
        ll bmin = Bmin[i];
        //cout << i << " " << bmin << " " << bmax << endl;
        if (bmax%A[i+1]!=0) {
            bmax -= bmax%A[i+1];
        }
        if (bmin%A[i+1]!=0) {
            bmin += A[i+1] - bmin%A[i+1];
        }
        //cout << i << " " << bmin << " " << bmax << endl;
        if ((bmin>Bmax[i]+A[i]-1) || (bmax<Bmin[i])) {
            t = false;
            break;
        }
        Bmax.push_back(bmax);
        Bmin.push_back(bmin);
    }

    if (t && A[0]==2) {

        cout << Bmin.back() << " " << Bmax.back()+A[K-1]-1 << endl;
    }
    else {
        cout << -1 << endl;
    }
}
