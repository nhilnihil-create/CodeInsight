#include <bits/stdc++.h>

using namespace std;
#define INF 1000007
#define MOD 1000000007
#define int long long
#define maxn 101
#define maxh 1001
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)
const int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
typedef std::pair<int, int> P;

vector<bool> prime(maxn + 1, true); //素数テーブル
void prime_table(void) {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (!prime[i]) {
            continue;
        }
        for (int j = i + i; j <= maxn; j += j + i) {
            prime[j] = false;
        }
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

bool IsPrime(int num) //素数判定
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> divisor(int n) //約数列挙
{
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i - 1);
            if (i * i != n) {
                ret.push_back((n / i) - 1);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return (ret);
}

int a, b;

void f(int x) {
    while (x) {
        a++;
        b = x;
        x /= 10;
    }
}

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];
    vector<vector<int>> ans(H, vector<int>(W, INF));
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<P> q;
    auto update = [&](int i, int j, int x) {
        if (dist[i][j] != INF) return;
        dist[i][j] = x;
        ans[i][j] = min(ans[i][j], dist[i][j]);
        q.push(P(i, j));
    };

    rep(si, H)
        rep(sj, W) {
            if (A[si][sj] != '#')continue;
            update(si, sj, 0);
        }
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        rep(dis, 4) {
            int ni = i + dx[dis];
            int nj = j + dy[dis];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W || (dist[ni][nj] != INF)) continue;
            if (A[ni][nj] == '#') {
                dist[ni][nj] = 0;
                continue;
            }
            update(ni, nj, dist[i][j] + 1);
        }
    }
    int ANS = 0;
    rep(i, H)
        rep(j, W) {
            ANS = max(ANS, ans[i][j]);
        }
    cout << ANS << endl;
}
