#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, H, maxA = 0;
    cin >> N >> H;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
        maxA = max(A.at(i), maxA);
    }
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    int i = 0;
    int sumB = 0;
    while (B.at(i) > maxA) {
        sumB += B.at(i);
        if (sumB >= H) {
            cout << i + 1 << endl;
            return 0;
        }
        i++;
        if (i == N) {
            break;
        }
    }
    H -= sumB;
    cout << i + H / maxA + (H % maxA + maxA - 1) / maxA << endl;
}