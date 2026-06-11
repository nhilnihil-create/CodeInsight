#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
 
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
vector<int> v(13);
vector<int> now;
int ans = 0;
 
void g() {
    int val = 25;
    for(int i = 0; i < now.size(); i++) {
        for(int j = i + 1; j < now.size(); j++) {
            int delta = abs(now[i] - now[j]);
            chmin(val, min(delta, 24 - delta));
        }
    }
    chmax(ans, val);
}
 
void f(int index) {
    if(index == 13) {
        g();
        return;
    }
    if(v[index] == 0) f(index + 1);
    if(v[index] == 1) {
        now.push_back(index);
        f(index + 1);
        now.pop_back();
        now.push_back(24 - index);
        f(index + 1);
        now.pop_back();
    }
    if(v[index] == 2) {
        now.push_back(index);
        now.push_back(24 - index);
        f(index + 1);
        now.pop_back();
        now.pop_back();
    }
}
 
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    v[0]++;
    for(int i = 1; i <= N; i++) {
        int D;
        cin >> D;
        if(v[D] == 2) {
            cout << 0 << endl;
            return 0;
        }
        v[D]++;
    }
    f(0);
    cout << ans << endl;
    return 0;
}