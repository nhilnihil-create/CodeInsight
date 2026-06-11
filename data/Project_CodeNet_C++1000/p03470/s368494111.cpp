#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;
    int d[N];
    rep(i, N) cin >> d[i];

    set<int> values;
    rep(i, N) values.insert(d[i]);

    cout << values.size() << endl;


    return 0;
}