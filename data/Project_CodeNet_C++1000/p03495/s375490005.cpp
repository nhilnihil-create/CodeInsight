#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        int b;
        cin >> b;
        a[b-1]++;
    }
    sort(a.begin(), a.end());
    reverse(all(a));

    int kr = 0;

    rep(i, k) {
        kr += a[i];
    }

    cout << n - kr << endl;

    return 0;
}