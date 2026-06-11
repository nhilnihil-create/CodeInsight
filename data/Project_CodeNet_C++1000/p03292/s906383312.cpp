#include <bits/stdc++.h>
using namespace std;

int main() {
    int A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    vector <int> A = {abs(A1-A2), abs(A2-A3), abs(A1-A3)};
    sort(A.begin(), A.end());
    cout << A.at(0)+A.at(1) << "\n";
}