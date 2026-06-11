#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    //sort(A.begin(), A.end());
    //sort(B.begin(), B.end());

    if(A == B) cout << 0 << endl;
    else{
        long long ans = accumulate(A.begin(), A.end(), (long long) 0);
        long long min_B = 1e+9;
        REP(i, N){
            if(A[i] > B[i]) min_B = min(min_B, B[i]);
        }
        cout << ans-min_B << endl;
    }

    return 0;
}