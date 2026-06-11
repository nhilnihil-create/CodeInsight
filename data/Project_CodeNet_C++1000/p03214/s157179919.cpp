#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};


//////////////////////////////////////////////////


int main() {
    double n; cin >> n;
    vector<double> a(n);
    double sum = 0;
    rep(i, n) cin >> a[i], sum+=a[i];

    double avg = sum/n;

    int ans = 0;
    repf(i, 1, n) {
        if (abs(a[i]-avg) < abs(a[ans]-avg)) ans = i;
    }
    
    cout << ans << endl;

    return 0;
}
