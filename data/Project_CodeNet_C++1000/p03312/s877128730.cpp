#include <bits/stdc++.h>
using namespace std;

long long diff(long long p, long long r, long long s, long long u) {
    return max(max(p, r), max(s, u)) - min(min(p, r), min(s, u));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }

    vector<long long> ac(N+1, 0);
    for (int i=1; i<=N; ++i) {
        ac[i] = ac[i-1] + A[i-1];
    }

    long long d = LLONG_MAX;
    int s1=1, s2=2, s3=3;
    while (s2 <= N-2) {
        while (s1+1 < s2 && abs(ac[s1+1] - (ac[s2]-ac[s1+1])) < abs(ac[s1] - (ac[s2]-ac[s1]))) {
            s1 ++;
        }
        while (s3+1 <= N-1 && abs((ac[s3+1]-ac[s2]) - (ac[N]-ac[s3+1])) < abs((ac[s3]-ac[s2]) - (ac[N]-ac[s3]))) {
            s3 ++;
        }
        d = min(d, diff(ac[s1], ac[s2]-ac[s1], ac[s3]-ac[s2], ac[N]-ac[s3]));
        s2 ++;
        s3 = max(s3, s2+1);
    }

    cout << d << endl;

    return 0;
}