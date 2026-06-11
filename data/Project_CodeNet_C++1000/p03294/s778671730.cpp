#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const long long INF = 1LL << 60;
const ll C = 1000000000+7;

int main(void)
{
    int N, ans = 0;
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
        ans += a[i] - 1;
    }
    cout << ans << endl;
}