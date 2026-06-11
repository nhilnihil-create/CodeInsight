#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<ll> a(X);
    vector<ll> b(Y);
    vector<ll> c(Z);
    for(int i = 0;i < X;i++) {
        cin >> a.at(i);
    }
    for(int i = 0;i < Y;i++) {
        cin >> b.at(i);
    }
    for(int i = 0;i < Z;i++) {
        cin >> c.at(i);
    }
    vector<ll> cnt;
    for(int i = 0;i < Y;i++) {
        for(int j = 0;j < Z;j++) {
            cnt.push_back(b.at(i) + c.at(j));
        }
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    vector<ll> cnt2;
    for(int i = 0;i < X;i++) {
        int A = cnt.size();
        for(int j = 0;j < min(K,A);j++) {
            cnt2.push_back(a.at(i) + cnt.at(j));
        }
    }
    sort(cnt2.begin(),cnt2.end());
    reverse(cnt2.begin(),cnt2.end());
    for(int i = 0;i < K;i++) {
        cout << cnt2.at(i) << endl;
    }
}