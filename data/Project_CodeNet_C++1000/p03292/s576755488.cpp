#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){
    vector<int> A(3);
    rep(i, 3) cin >> A[i];

    sort(A.begin(), A.end());
    cout << A[2]-A[0] << endl;
}