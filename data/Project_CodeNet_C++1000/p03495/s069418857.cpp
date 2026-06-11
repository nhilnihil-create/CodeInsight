#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    int N; cin >> N;
    int K; cin >> K;

    vector<int> A;
    rep(i, N) {
        int atmp; cin >> atmp; A.push_back(atmp);
    }

    // バケット
    int b[N+1];
    rep(i, N+1) b[i] = 0;
    
    set<int> st;
    rep(i, N) {
        st.insert(A[i]);
        b[A[i]]++;
    }

    int k = st.size();
    int diff = k - K;
    if (diff <= 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(b, b + N + 1);
    
    int count = 0;
    int diff2 = 0;
    rrep(i, 1, N) {
        if (b[i] == 0) continue;
        diff2++;
        count+=b[i];
        if (diff2 == diff) break;
    }

    cout << count << endl;
    return 0;
}
