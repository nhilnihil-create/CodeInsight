#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    while(Q--){
        int64_t A, B;
        cin >> A >> B;
        if(A > B) swap(A, B);
        int64_t ok = 0, ng = B;
        while(ng-ok>1){
            int64_t mid = (ng+ok)/2;
            int64_t res = max(A+mid, mid*(A+1));
            if(A <= mid){
                int64_t s = A+1+mid;
                res = max(res, s/2*(s-s/2));
            }
            (res < A*B ? ok : ng) = mid;
        }
        int64_t ans = A-1+ok;
        cout << ans << endl;
    }
}