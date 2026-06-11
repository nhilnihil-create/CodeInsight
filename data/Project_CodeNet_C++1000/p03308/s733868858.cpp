#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) {
        cin >> A.at(i);
    }
    int dif = 0;
    for (int i=0;i<N-1;i++) {
        for (int j=i+1;j<N;j++) {
            dif = max(dif,abs(A.at(i)-A.at(j)));
        }
    }
    cout << dif << endl;
}
