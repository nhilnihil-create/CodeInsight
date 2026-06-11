#include <bits/stdc++.h>
using namespace std;
struct data {
    int w, s, v;
    bool operator<(const data& rhs) const {
        return w + s < rhs.w + rhs.s;
    }
};
int main()
{
    int N; cin >> N;
    vector<struct data> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].w >> A[i].s >> A[i].v;
    }
    sort(begin(A), end(A));
    vector<long long> value(20001);
    for (int i = 0; i < N; i++) {
        for (int j = A[i].s; j >= 0; j--) {
            value[j + A[i].w] = max(value[j + A[i].w], value[j] + A[i].v);
        }
    }
    cout << *max_element(begin(value), end(value)) << endl;
    return 0;
}