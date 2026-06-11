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
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> cnt(3);
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        if (p <= A) cnt[0]++;
        else if (p <= B) cnt[1]++;
        else cnt[2]++;
    }
    cout << *min_element(cnt.begin(), cnt.end()) << '\n';
}
