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
    cin>>N;
    vi A(N), B(N), C(N);
    REP(i, 0, N) cin >> A[i];
    REP(i, 0, N) cin >> B[i];
    REP(i, 0, N) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    long ans = 0;
    REP(i, 0, N){
        int b = B[i];
        auto a_Itr =lower_bound(A.begin(), A.end(), b);
        auto c_Itr =upper_bound(C.begin(), C.end(), b);
        ans += (long)(a_Itr - A.begin()) * (long)(C.end() - c_Itr);
    }
    cout << ans << endl;
}