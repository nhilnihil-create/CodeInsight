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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = INF;
    A.push_back(-1);
    for (int x : A) {
        vector<vector<int> > sp;
        vector<int> tmp;
        for (int a : A) {
            if (x <= a) tmp.push_back(a);
            else {
                sp.push_back(tmp);
                tmp.clear();
            }
        }
        vector<int> m;
        for (vector<int> s : sp) {
            if (s.size() >= K) {
                sort(s.begin(), s.end());
                m.insert(m.end(), s.begin(), s.begin() + s.size() - K + 1);
            }
        }
        if (m.size() >= Q) {
            sort(m.begin(), m.end());
            int y = m[Q - 1];
            ans = min(ans, y - x);
        }
    }
    cout << ans << '\n';
}