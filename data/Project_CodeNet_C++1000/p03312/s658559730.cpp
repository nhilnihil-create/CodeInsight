#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N), S(N+1);
    for(int i=0; i<N; i++){
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }

    int64_t ans = 1e18;

    int pt1 = 1, pt2 = 3;
    for(int s=2; s<N-1; s++){
        int64_t S1 = S[s], S2 = S[N] - S[s];
        while(pt1 < s && 2*S[pt1] < S1) pt1++;
        while(pt2 < N && 2*(S[pt2] - S[s]) < S2) pt2++;
        int64_t mx1 = min(S[pt1], S1 - S[pt1-1]);
        int64_t mn1 = S1 - mx1;
        int64_t mx2 = min(S[pt2] - S[s], S2 - (S[pt2-1] - S[s]));
        int64_t mn2 = S2 - mx2;
        int64_t res = max(mx1, mx2) - min(mn1, mn2);
        ans = min(ans, res);
    }
    cout << ans << endl;
}