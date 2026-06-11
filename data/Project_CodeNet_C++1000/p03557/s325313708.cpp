#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t>A(N);
    vector<int64_t>B(N);
    vector<int64_t>C(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }

    for (int i=0; i<N; i++) {
        cin >> B.at(i);
    }

    for (int i=0; i<N; i++) {
        cin >> C.at(i);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    map<int64_t, int64_t>d;
    int64_t sum_ = 0;
    for (int64_t i=N-1; i>=0; i--) {
        auto itr = upper_bound(C.begin(), C.end(), B[i]);
        int64_t count = C.end() - itr;
        sum_ += count;
        d[B[i]] = sum_;
    }

    int64_t count = 0;
    for (int i=0; i<N; i++) {
        auto itr = upper_bound(B.begin(), B.end(), A[i]);
        int64_t index = itr - B.begin();
        if (itr != B.end()) {
            count += d[B[index]];
        }
    }

    cout << count << endl;
    return 0;
}