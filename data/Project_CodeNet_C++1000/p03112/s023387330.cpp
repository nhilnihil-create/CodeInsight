#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> S(A + 2);
    S.at(0) = -INF;
    for(int i = 1;i < A + 1;i++) {
        cin >> S.at(i);
    }
    S.at(A + 1) = INF;
    vector<ll> T(B + 2);
    T.at(0) = -INF;
    for(int i = 1;i < B + 1;i++) {
        cin >> T.at(i);
    }
    T.at(B + 1) = INF;
    for(int i = 0;i < Q;i++) {
        ll x;
        cin >> x;
        ll ret = INF;
        auto itr1 = upper_bound(S.begin(),S.end(),x);
        auto itr2 = upper_bound(T.begin(),T.end(),x);
        int a = itr1 - S.begin();
        int b = itr2 - T.begin();
        ret = min(ret,max(S.at(a),T.at(b)) - x);
        ret = min(ret,x - min(S.at(a - 1),T.at(b - 1)));
        ret = min(ret,min(S.at(a) - x,x - T.at(b - 1)) + (S.at(a) - T.at(b - 1)));
        ret = min(ret,min(T.at(b) - x,x - S.at(a - 1)) + (T.at(b) - S.at(a - 1)));
        cout << ret << endl;
    }
}