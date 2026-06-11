#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 5e36+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N),B(N);
    vector<P>cnt(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        cnt[i].first = A[i]+B[i];
        cnt[i].second = i;
    }
    sort(cnt.rbegin(),cnt.rend());
    int Takahashi = 0,Aoki = 0;
    for(int i = 0; i < N; i++) {
        ((i%2 == 0)?Takahashi+=A[cnt[i].second]:Aoki+=B[cnt[i].second]);
    }
    cout << Takahashi-Aoki << endl;
}
