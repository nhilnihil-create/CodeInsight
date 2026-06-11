#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define countof(a) (sizeof(a)/sizeof((a)[0]))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define all(a) begin(a),end(a)

signed main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    int N,A,B; cin >> N >> A >> B;
    int counter[3] = {0, 0, 0};

    int P;
    rep(i, N) {
        cin >> P;
        if (P <= A)      counter[0]++;
        else if (P <= B) counter[1]++;
        else             counter[2]++;
    }

    cout << min(counter[0], min(counter[1], counter[2])) << endl;
}
