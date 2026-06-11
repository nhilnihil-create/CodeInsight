#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];

    cout << accumulate(v.begin(), v.end(), 0) - n << endl;

    return 0;
}
    