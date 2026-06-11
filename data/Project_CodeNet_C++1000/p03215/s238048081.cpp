#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N,K;
    cin >> N >> K;
    vector<ll> cnt(N + 1);
    cnt.at(0) = 0;
    for(int i = 1;i < N + 1;i++) {
        cin >> cnt.at(i);
    }
    for(int i = 0;i < N;i++) {
        cnt.at(i + 1) += cnt.at(i);
    }
    vector<ll> cnt2;
    for(int i = 0;i < N;i++) {
        for(int j = i + 1;j < N + 1;j++) {
            ll C = cnt.at(j) - cnt.at(i);
            cnt2.push_back(C);
        }
    }
    int A = cnt2.size();
    vector<vector<int>> cnt3(A,vector<int>(41));
    for(int i = 0;i < A;i++) {
        for(int j = 0;j < 41;j++) {
            cnt3.at(i).at(j) = cnt2.at(i) % 2;
            cnt2.at(i) /= 2;
        }
    }
    ll ret = 0;
    vector<bool> flag(A,true);
    for(int i = 40;i >= 0;i--) {
        int count = 0;
        for(int j = 0;j < A;j++) {
            if(flag.at(j) == true && cnt3.at(j).at(i) == 1) {
                count++;
            }
        }
        if(count >= K) {
            ret += pow(2,i);
            for(int j = 0;j < A;j++) {
                if(cnt3.at(j).at(i) == 0) {
                    flag.at(j) = false;
                }
            }
        }
    }
    cout << ret << endl;
}