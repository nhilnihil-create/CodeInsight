#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, Q, tmp=0;
vector<vector<ll>> T, R, A;

signed main(){
    cin >> N >> M >> Q;
    T.resize(N);
    R.resize(N);
    A.resize(N);
    for(int i=0;i<T.size();i++) {
        T[i].resize(N,0);
        R[i].resize(N,0);
        A[i].resize(N,0);
    }
    for(int i=0;i<M;i++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        T[l][r]++;
    }
    for(int i=0;i<N;i++) {
        for(int j=i;j<N;j++) {
            if(j>0) R[i][j] = R[i][j-1]+T[i][j];
            else R[i][j] = T[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=i;j>=0;j--) {
            if(j==i) A[j][i] = R[j][i];
            else A[j][i] = A[j+1][i]+R[j][i];
        }
    }
    for(int i=0;i<Q;i++) {
        ll p, q;
        cin >> p >> q;
        p--;
        q--;
        cout << A[p][q] << endl;
    }
    return 0;
}