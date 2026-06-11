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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    vector<int> C(M);
    rep(i,N) {
        cin >> A[i];
    }
    rep(i,M) {
        cin >> B[i] >> C[i];
    }

    ll ans = 0;

    sort(A.begin(),A.end());

    vector<int> idx(M);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int i, int j) {
            return C[i] > C[j];});

    int id = 0;
    rep(i,A.size()) {

        if (A[i]<C[idx[id]]) {
            A[i] = C[idx[id]];
            B[idx[id]]--;
            if (id+1==idx.size()&&B[idx[id]]==0) {
                break;
            }
            if (B[idx[id]]==0) {
                id++;
            }
        }
        else {
            break;
        }
    }
    rep(i,A.size()) {
        ans += A[i];
    }
    cout << ans << endl;

}
