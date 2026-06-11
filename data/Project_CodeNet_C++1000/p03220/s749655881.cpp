#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    long t, a;
    cin >> t >> a;

    vector<long> h(n);
    rep(i,n) {
        cin >> h.at(i);
    }

    vector<long> tempDif(n);
    rep(i,n) {
        tempDif.at(i) = abs(a*1000-(t*1000-h.at(i)*6));
    }

    int index = min_element(tempDif.begin(), tempDif.end()) - tempDif.begin();

    cout << index+1 << endl;
    return 0;
}