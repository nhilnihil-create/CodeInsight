#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,int> P;

int main() {
    int N,M;
    cin >> N >> M;
    vector<tuple<ll,ll,ll>> vec(N);
    for(int i = 0;i < N;i++) {
        ll A,B,C;
        cin >> A >> B >> C;
        vec.at(i) = make_tuple(A,B,C);
    }
    ll ret = 0;
    for(int i = 0;i < 2;i++) {
        for(int j = 0;j < 2;j++) {
            for(int k = 0;k < 2;k++) {
                ll A,B,C;
                if(i == 0) {
                    A = 1;
                }
                else {
                    A = -1;
                }
                if(j == 0) {
                    B = 1;
                }
                else {
                    B = -1;
                }
                if(k == 0) {
                    C = 1;
                }
                else {
                    C = -1;
                }
                vector<P> cnt(N);
                for(int l = 0;l < N;l++) {
                    cnt.at(l) = P(A * get<0>(vec.at(l)) + B * get<1>(vec.at(l)) + C * get<2>(vec.at(l)),l);
                }
                sort(cnt.begin(),cnt.end());
                reverse(cnt.begin(),cnt.end());
                ll a = 0;
                ll b = 0;
                ll c = 0;
                for(int l = 0;l < M;l++) {
                    a += get<0>(vec.at(cnt.at(l).second));
                    b += get<1>(vec.at(cnt.at(l).second));
                    c += get<2>(vec.at(cnt.at(l).second));
                }
                if(a <= 0) {
                    a = -a;
                }
                if(b <= 0) {
                    b = -b;
                }
                if(c <= 0) {
                    c = -c;
                }
                ret = max(ret,a + b + c);
            }
        }
    }
    cout << ret << endl;
}