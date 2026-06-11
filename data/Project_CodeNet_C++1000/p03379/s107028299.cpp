//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    int left = n/2 - 1;
    int right = n/2;

    rep(i, n) {
        int value = a[i];
        if(lower_bound(b.begin(), b.end(), value) - b.begin() <= left) {
            cout << b[right] << endl;
        }else{
            cout << b[left] << endl;
        }
    }

    return 0;
}
