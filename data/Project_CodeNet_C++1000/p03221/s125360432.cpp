//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int> > py(m);
    rep(i, m) {
        cin >> get<0>(py[i]) >> get<1>(py[i]);
        get<2>(py[i]) = i;
    } 

    sort(py.begin(), py.end());

    int j=1;
    rep(i, m) {
        get<3>(py[i]) = j;
        if(i!=m-1 && get<0>(py[i]) == get<0>(py[i+1])) {
            ++j;
        } else {
            j=1;
        }
    }

    rep(i, m) {
        swap(get<2>(py[i]), get<0>(py[i]));
    }
    sort(py.begin(), py.end());

    rep(i, m) {
        printf("%06d%06d\n", get<2>(py[i]), get<3>(py[i]));
    }
}