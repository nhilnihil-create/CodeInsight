#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t Int;
using namespace std;


int main(){
    int A, B, Q;
    vector<Int> S(100010, -1e11), T(100010, -1e11);

    cin >> A >> B >> Q;
    rep(i, A) cin >> S[i+1];
    rep(i, B) cin >> T[i+1];
    sort(S.begin(), S.begin()+A+1);
    sort(T.begin(), T.begin()+B+1);
    S[A+1] = 1e11; T[B+1] = 1e11;

    rep(query, Q){
        Int x; cin >> x;

        Int rightS = *lower_bound(S.begin(), S.begin()+A+2, x);
        Int leftS = *(lower_bound(S.begin(), S.begin()+A+2, x)-1);
        Int rightT = *lower_bound(T.begin(), T.begin()+B+2, x);
        Int leftT = *(lower_bound(T.begin(), T.begin()+B+2, x)-1);
        //cout << rightS << " " << leftS << " " << rightT << " " << leftT << endl;
        
        Int rSrT = max(rightS, rightT) - x;
        Int rSlT = 2*min(x-leftT, rightS-x)+max(x-leftT, rightS-x);
        Int lSrT = 2*min(x-leftS, rightT-x)+max(x-leftS, rightT-x);
        Int lSlT = x - min(leftS, leftT);

        cout << min(rSrT, min(rSlT, min(lSrT, lSlT))) << endl;
    }
}