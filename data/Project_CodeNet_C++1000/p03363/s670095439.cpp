#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> A(N);
    for (long long i=0; i<N; i++) cin >> A.at(i);
    vector <long long> s(N+1, 0);
    map<long long, long long> m;
    m[0]++;
    for (long long i=0; i<N; i++) {
        s.at(i+1) = s.at(i) + A.at(i);
        m[s.at(i+1)]++;
    }
    long long res = 0;
    for (auto it : m) {
        res += it.second * (it.second-1) / 2;
    }
    cout << res << endl;
}