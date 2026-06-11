#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> a(N);
    int sum = 0;
    rep(i, N) {
        cin >> a[i];
        sum += a[i];
    }
    double avg = (double)sum / N;
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        if (a[x] == a[y])
            return x < y;
        return fabs(a[x]-avg) < fabs(a[y]-avg);
    });

    cout << idx[0] << endl;
}
