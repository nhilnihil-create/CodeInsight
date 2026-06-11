#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long N;
    cin >> N;
    vector<long long>A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    long long time = (N+A.at(0)-1)/A.at(0) + 4;
    cout << time << endl;
}