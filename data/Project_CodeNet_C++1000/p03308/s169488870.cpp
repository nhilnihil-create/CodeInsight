#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++){
        cin >> A.at(i);
    }

    int max = A.at(0), min = A.at(0);
    for (int i=0; i<N; i++){
        if (max < A.at(i)) max = A.at(i);
        if (min > A.at(i)) min = A.at(i);
    }
    cout << max - min << endl;
}