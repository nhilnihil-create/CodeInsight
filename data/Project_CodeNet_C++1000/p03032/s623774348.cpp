#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    int maxV = 0;
    for (int l = 0; l <= K; l++) {
        for (int r = 0; r <= K; r++) {
            int outNum = l + r;
            if (outNum > min(N,K)) continue;
            int rest = K - outNum;
            vector<int> hand;
            hand.insert(hand.end(), v.begin(), v.begin() + l);
            hand.insert(hand.end(), v.rbegin(), v.rbegin() + r);
            sort(hand.begin(), hand.end());
            int tmp = 0;
            for (int i = 0; i < outNum; i++) {
                if (i < rest && hand[i] < 0) continue;
                tmp += hand[i];
            }
            maxV = max(tmp, maxV);
        }
    }
    cout << maxV << '\n';
}
