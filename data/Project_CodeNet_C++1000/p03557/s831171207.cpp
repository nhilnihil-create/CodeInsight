#include <bits/stdc++.h>
using namespace std;



int main() {
    long long N, a, b, c;
    long long ans = 0;
    vector<int> A, B, C;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < N; i++){
        cin >> b;
        B.push_back(b);
    }
    for (int i = 0; i < N; i++){
        cin >> c;
        C.push_back(c);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    for (auto b: B){
        long long less_than_b = distance(A.begin(), lower_bound(A.begin(), A.end(), b));
        long long greater_than_b = C.size() - distance(C.begin(), upper_bound(C.begin(), C.end(), b));
        ans += less_than_b * greater_than_b;
    }
    cout << ans << endl;
}
