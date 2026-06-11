#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    for(int i = 0;i < N;i++) {
        cin >> A.at(i);
    }
    for(int i = 0;i < N;i++) {
        cin >> B.at(i);
    }
    vector<ll> cnt(N);
    for(int i = 0;i < N;i++) {
        cnt.at(i) = A.at(i) - B.at(i);
    }
    int ret = 0;
    sort(cnt.begin(),cnt.end());
    ll cnt2 = 0;
    for(int i = 0;i < N;i++) {
        if(cnt.at(i) < 0) {
            cnt2 += abs(cnt.at(i));
        }
        else {
            break;
        }
        ret++;
    }
    bool res = true;
    reverse(cnt.begin(),cnt.end());
    for(int i = 0;i < N;i++) {
        if(cnt.at(i) <= 0) {
            res = false;
            break;
        }
        else if(cnt2 <= 0) {
            break;
        }
        else {
            ret++;
            cnt2 -= cnt.at(i);
            if(cnt2 <= 0) {
                break;
            }
        }
    }
    if(res == false) {
        cout << -1 << endl;
    }
    else {
        cout << ret << endl;
    }
}