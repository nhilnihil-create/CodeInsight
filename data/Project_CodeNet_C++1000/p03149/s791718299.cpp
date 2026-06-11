#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    vector<int> A(4);
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    sort(A.begin(), A.end());
    if (A[0] == 1 && A[1] == 4 && A[2] == 7 && A[3] == 9)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
