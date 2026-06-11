#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll s = 0;
    ll a_min = 1000000007;
    int m_cnt = 0;
    rep(i, n){
        ll a;
        cin >> a;
        s += abs(a);
        a_min = min(a_min, abs(a));
        if(a < 0) m_cnt++;
    }
    if(m_cnt % 2 == 0){
        cout << s << endl;
    } else {
        cout << s - 2 * a_min << endl;
    }

    
    return 0;
}
