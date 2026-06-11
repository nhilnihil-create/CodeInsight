#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

ll Pow(ll a,ll b) {
    ll ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<int> bit1(40);
    vector<vector<int>> bit2(N,vector<int>(40));
    for(int i = 0;i < 40;i++) {
        bit1.at(i) = K % 2;
        K /= 2;
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < 40;j++) {
            bit2.at(i).at(j) = vec.at(i) % 2;
            vec.at(i) /= 2;
        }
    }
    ll ret = 0;
    bool flag = true; //決め打ちしたところがKと同じかどうか
    for(int i = 39;i >= 0;i--) {
        ll zero = 0;
        ll one = 0;
        for(int j = 0;j < N;j++) {
            if(bit2.at(j).at(i) == 0) {
                one++;
            }
            else {
                zero++;
            }
        }
        if(zero > one) {
            if(bit1.at(i) == 1) {
                flag = false;
            }
            ret += zero * Pow(2,i);
        }
        else if(zero < one) {
            if(flag == true) {
                if(bit1.at(i) == 0) {
                    ret += zero * Pow(2,i);
                }
                else {
                    ret += one * Pow(2,i);
                }
            }
            else {
                ret += one * Pow(2,i);
            }
        }
        else {
            ret += zero * Pow(2,i);
            if(bit1.at(i) == 1) {
                flag = false;
            }
        }
    }
    cout << ret << endl;
}