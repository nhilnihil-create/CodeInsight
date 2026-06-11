#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2009;
vector< int >forbidden;
int a[MAXN];

int getX(int n, int k, int q) {
    vector< int >w;
    for (int i = 1; i < forbidden.size(); i++) {
        int len = forbidden[i]-forbidden[i-1]-k;
//        cout << "(" << forbidden[i-1] << "," << forbidden[i] << ")" << endl;
        if (len <= 0) continue;
        vector< int >v;
        for (int j = forbidden[i-1]+1; j < forbidden[i]; j++) v.push_back(a[j]);
        sort(v.begin(), v.end());
        for (int j = 0; j < len; j++) {
//            cout << "got " << v[j] << endl;
            w.push_back(v[j]);
        }
    }

    if (w.size() < q) return -1;
    sort(w.begin(), w.end());
    return w[q-1];
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector< int >v(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i-1] = a[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int ans = v.back()-v.front();

    forbidden.push_back(0);
    forbidden.push_back(n+1);

    for (int y : v) {
//        cout << "with " << y << endl;
        int x = getX(n, k, q);
        if (x != -1) ans = min(ans, x-y);

        for (int i = 1; i <= n; i++) {
            if (a[i]==y) forbidden.push_back(i);
        }
        sort(forbidden.begin(), forbidden.end());
    }

    cout << ans << endl;

    return 0;
}
