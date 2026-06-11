#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    vector<ll> A(3);
    for (auto & a : A) cin >> a;
    sort(A.begin(), A.end());
    cout << A[2] - A[0] << endl;
}
