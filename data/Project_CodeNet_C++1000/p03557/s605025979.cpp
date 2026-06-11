#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N;
    cin >> N;
    vl A(N), B(N), C(N);
    REP(i, 0, N) cin >> A[i];
    REP(i, 0, N) cin >> B[i];
    REP(i, 0, N) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    vl B_count(N), B_cum(N);

    long ans = 0;
    REP(i, 0, N){
        int b = B[i];
        auto c_Itr = upper_bound(C.begin(), C.end(), b);
        B_count[i] = C.end() - c_Itr;
    }
    B_cum[N-1] = B_count[N-1];
    for(int i = N-2; i>=0 ;i--){
        B_cum[i] = B_cum[i+1] + B_count[i];
    }
    REP(i, 0, N){
        int a = A[i];
        auto b_Itr = upper_bound(B.begin(), B.end(), a);
        ans += B_cum[b_Itr - B.begin()];
    }
    cout << ans << endl;

}