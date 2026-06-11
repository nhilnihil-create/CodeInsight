#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector <int> a(N, 0);
    for (long long i=0; i<N; i++) {
        if (i+1 < N && S.at(i)=='A' && S.at(i+1)=='C') a.at(i) = 1;
    }
    vector <long long> s(N+1, 0);
    for (long long i=0; i<N; i++) {
        s.at(i+1) = s.at(i) + a.at(i); 
    }
    vector <long long> ans(Q);
    for (long long i=0; i<Q; i++) {
        long long l,r;
        cin >> l >> r;
        ans.at(i) = s.at(r-1) - s.at(l-1);
    }
    for (long long i=0; i<Q; i++) cout << ans.at(i) << endl;
}