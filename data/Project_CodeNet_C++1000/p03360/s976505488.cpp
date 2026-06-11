#include<bits/stdc++.h>
using namespace std;

int main() {
    int K;
    vector<int> A(3);
    for (int i=0; i<3; i++) cin >> A.at(i);
    cin >> K;
    sort(A.begin(), A.end());
    cout << A.at(0) + A.at(1) + A.at(2)*pow(2,K) << "\n";
}