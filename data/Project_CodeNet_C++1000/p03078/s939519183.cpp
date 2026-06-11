#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    REP(i, X) cin >> A[i];
    REP(i, Y) cin >> B[i];
    REP(i, Z) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<ll> sumBC;
    REP(i, Y) REP(j, Z) sumBC.push_back(B[i] + C[j]);
    sort(sumBC.rbegin(), sumBC.rend());
    vector<int> maxSumIndex(X, 0);
    REP(i, K)
    {
        ll sumMax = -1;
        int argMaxIndex;
        REP(j, X)
        {
            if (maxSumIndex[j] < Y * Z)
            {
                if (A[j] + sumBC[maxSumIndex[j]] > sumMax)
                {
                    sumMax = A[j] + sumBC[maxSumIndex[j]];
                    argMaxIndex = j;
                }  
            }
        }
        cout << sumMax << endl;
        maxSumIndex[argMaxIndex]++;
    }
}
