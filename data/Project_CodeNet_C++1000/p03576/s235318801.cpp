#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const ll INF = 9223372036854775807;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N,K;
    cin >> N >> K;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        ll A,B;
        cin >> A >> B;
        vec.at(i) = P(A,B);
    }
    vector<int> x(N);
    vector<int> y(N);
    for(int i = 0;i < N;i++) {
        x.at(i) = vec[i].first;
        y.at(i) = vec[i].second;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll ret = INF;
    for(int i = 0;i < N - 1;i++) {
        for(int j = i + 1;j < N;j++) {
            for(int k = 0;k < N - 1;k++) {
                for(int l = k + 1;l < N;l++) {
                    ll x1 = x.at(i);
                    ll x2 = x.at(j);
                    ll y1 = y.at(k);
                    ll y2 = y.at(l);
                    int cnt = 0;
                    for(int m = 0;m < N;m++) {
                        if(x1 <= vec[m].first && vec[m].first <= x2 && y1 <= vec[m].second && vec[m].second <= y2) {
                            cnt++;
                        }
                    }
                    if(cnt >= K) {
                        ll cnt2 = (x2 - x1) * (y2 - y1);
                        ret = min(ret,cnt2);
                    }
                }
            }
        }
    }
    cout << ret << endl;
}