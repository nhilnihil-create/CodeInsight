#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;

    vector<unsigned long long> A(90);
    A.at(0) = 2;
    A.at(1) = 1;
    for (size_t i = 2; i < 90; i++)
    {
        A.at(i) = A.at(i-1)+A.at(i-2);
    }
    cout << A.at(N) << endl;

    return 0;
}
