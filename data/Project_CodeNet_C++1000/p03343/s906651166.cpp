#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
 
int main() {
    int N, K, Q; cin >> N >> K >> Q;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    vector<ll> B(A);
    sort(all(B));
    A.push_back(-1);
    B.push_back(INF);
    ll ans = INF;
    REP(left,N) {
        int ub = N;
        int lb = left-1;
        int right;
        while(ub-lb>1) {
            right = (ub + lb) / 2;
            int cnt = 0;
            int cnt1 = 0;
            int cnt2 = 0;
            REP(i,N) {
                if (B[left]<=A[i]) cnt1++;
                if (B[left]<=A[i] && A[i]<=B[right]) cnt2++;
                if (A[i+1]<B[left]){
                    cnt += min(max(0,cnt1-K+1),cnt2);
                    cnt1 = 0;
                    cnt2 = 0;
                }
            }
            if (cnt>=Q) ub = right;
            else lb = right;
        }
        ans = min(ans, B[ub]-B[left]);
    }
    cout << ans << endl;
}