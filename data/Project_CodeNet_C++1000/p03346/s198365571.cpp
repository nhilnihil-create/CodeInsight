#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll ZERO = 0;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        A--;
        vec.at(i) = A;
    }
    vector<int> cnt(N);
    for(int i = 0;i < N;i++) {
        cnt.at(vec.at(i)) = i;
    }
    int ret = 0;
    int cnt2 = 1;
    for(int i = 0;i < N - 1;i++) {
        if(cnt.at(i) < cnt.at(i + 1)) {
            cnt2++;
        }
        else {
            ret = max(ret,cnt2);
            cnt2 = 1;
        }
    }
    ret = max(ret,cnt2);
    cout << N - ret << endl;
}