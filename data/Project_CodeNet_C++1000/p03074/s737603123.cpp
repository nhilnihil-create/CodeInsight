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
    int N, K; cin >> N >> K;
    string S;
    cin >> S;
    vector<int> list;
    if(S[0] == '0') list.emplace_back(0);
    char pre = S[0];
    int count = 0;
    rp(i, 0, N) {
        if(pre != S[i]) {
            list.emplace_back(count);
            count = 0;
        }
        count++;
        pre = S[i];
    }
    list.emplace_back(count);
    if(S[N-1] == '0') list.emplace_back(0);
    // rp(i, 0, int(list.size())) {
    //     cout << list.at(i) << endl;
    // }
    int ans = 0;
    int l = list.size();
    if(2 * K >= l-1) {
        ans = N;
    } else {
        int now = 0;
        rp(i, 0, 2 * K + 1) {
            now += list.at(i);
        }
        ans = now;
        int s = 0;
        while(1) {
            now += list.at(2*K+s+1) + list.at(2*K+s+2);
            now -= list.at(s+1) + list.at(s);
            chmax(ans, now); 
            if(s + 2 * K + 2 >= l - 1) break;
            s+=2;
        }
    }
    cout << ans << endl;
    return 0;

}