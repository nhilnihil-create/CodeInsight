#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int>A(N);
    vector<int>cnt(200000);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]-1]++;
    }
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    int cnt2 = 0;
    for(int i = 0; i < K; i++) {
        cnt2+=cnt[i];
    }
    cout << N-cnt2 << endl;
}