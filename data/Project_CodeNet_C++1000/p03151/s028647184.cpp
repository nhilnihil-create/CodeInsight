#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define maxs(x,y) x = max(x, y)
#define mins(x,y) x = min(x, y)
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    ll N;
    cin >> N;

    ll sumA = 0, sumB = 0;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
        sumA += A[i];
    }

    vector<ll> B(N);
    REP(i, N) {
        cin >> B[i];
        sumB += B[i];
    }

    if (sumA < sumB) {
        cout << -1 << endl;
        return 0;
    }

    ll fusoku = 0;
    vector<ll> yuyo;
    ll cnt = 0;
    REP(i, N) {
        if (A[i] < B[i]) {
            fusoku += B[i] - A[i];
            cnt ++;
        }
        if (A[i] > B[i]) yuyo.push_back(A[i] - B[i]);
    }

    sort(RALL(yuyo));

    while(fusoku > 0) {
        fusoku -= yuyo[0];
        cnt++;
        yuyo.erase(yuyo.begin());
    }


    cout << cnt << endl;

    return 0;
}