#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
#define PI  acos(-1)
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
typedef long double ld;
int main() {
    int h, w, d,l,r,q; cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    vector<pair<int, int>> v(h*w+1);
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        v[a[i][j] - 1] = make_pair(i,j);
    }vector<int> s(h* w + 1, 0);
    rep(i, h* w -d) {
        s[i + d] += s[i] + abs(v[i].first - v[i + d].first) + abs(v[i].second - v[i + d].second);
    }cin >> q;
    rep(i, q) {
        cin >> l >> r; l--; r--;
        cout << s[r] - s[l] << endl;
    }
}