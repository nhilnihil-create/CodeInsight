#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

bool comp(P p1, P p2){
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    }
    else if (p1.second != p2.second) {
        return p1.second > p2.second;
    }
    else {
        return true;
    }
}


int main () {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    map<ll,ll> S;
    rep(i,N) {
        cin >> A[i];
    }
    rep(i,M) {
        ll b,c;
        cin >> b >> c;
        if (!S.count(c)) {
            S[c] = b;
        }
        else {
            S[c] += b;
        }
    }

    sort(A.begin(),A.end());
    
    rep(i,A.size()) {
        auto iter = S.end();
        iter--;
        if (A[i]<iter->first) {
            A[i] = iter->first;
            iter->second --;
            if (iter->second==0) {
                S.erase(iter->first);
                if (S.size()==0) {
                    break;
                }
            }
        }     
    }
    ll ans = 0;
    rep(i,A.size()) {
        ans += A[i];
    }

    cout << ans << endl;

}
