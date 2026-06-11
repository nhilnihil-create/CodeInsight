#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> A, B, C;
    rp(i, 0, x) {
        ll a;
        cin >> a;
        A.emplace_back(a);
    }
    rp(i, 0, y) {
        ll b; cin >> b;
        rp(j, 0, x) {
            B.emplace_back(A[j] + b);
        }
    }
    rp(i, 0, z) {
        ll a;
        cin >> a;
        C.emplace_back(a);
    }
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    priority_queue< ll, vector<ll>, greater<ll> > value;
    rp(i, 0, x*y) {
        bool flag = 1;
        int j = 0;
        while(flag) {
            if(j >= z) flag = 0;
            else if(int(value.size()) < k){
                value.push(B[i] + C[j]);
                j++;
            }
            else{
                if(value.top() >= B[i] + C[j]) flag = 0;
                else {
                    value.push(B[i] + C[j]);
                    value.pop();
                    j++;
                }
            }
        }
    }
    vector<ll> res;
    while(!value.empty()) {
        res.emplace_back(value.top()); value.pop();
    }
    for(int i = k-1; i >= 0; i--) cout << res[i] << endl;
    return 0;
}