#include <bits/stdc++.h>

using namespace std;

int main() {
    /* code */
    int N = 3;
   // cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    int n = A.at(2)+A.at(2)-A.at(1)-A.at(0);

    cout << n/2 +(n%2)*2 << endl;
    return 0;
}