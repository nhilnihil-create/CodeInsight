#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int result = INT_MAX;
    for (int lb: A) {
        vector<int> v;
        int first = 0;
        int last;
        while (first < N) {
            while (first < N && A[first] < lb) {
                ++first;
            }
            last = first;
            while (last < N && A[last] >= lb) {
                ++last;
            }
            if (last - first >= K) {
                vector<int> temp(A.begin() + first, A.begin() + last);
                sort(all(temp));
                REP(i, last - first - K + 1) {
                    v.push_back(temp[i]);
                }
            }
            first = last + 1;
        }
        if (v.size() >= Q) {
            sort(all(v));
            result = min(result, v[Q - 1] - v[0]);
        }
    }
    cout << result << endl;
    return 0;
}