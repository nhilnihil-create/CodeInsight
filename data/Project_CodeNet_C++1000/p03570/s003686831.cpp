#include <bits/stdc++.h>

#define show(x) cerr << #x << " = " << x << endl

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "sz:" << v.size() << "\n[";
    for (const auto& p : v) {
        os << p << ",";
    }
    os << "]\n";
    return os;
}

template <typename S, typename T>
ostream& operator<<(ostream& os, const pair<S, T>& p)
{
    os << "(" << p.first << "," << p.second
       << ")";
    return os;
}


constexpr ll MOD = (ll)1e9 + 7LL;

template <typename T>
constexpr T INF = numeric_limits<T>::max() / 100;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    const int N = s.size();

    vector<int> prev(26, 0);
    vector<int> now(26, 0);
    vector<int> value(N);
    for (int i = 0; i < N; i++) {
        now[s[i] - 'a'] = (prev[s[i] - 'a'] + 1) % 2;
        for (int j = 0; j < 26; j++) {
            value[i] += (int)now[j] << j;
        }
        prev = now;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += prev[i];
    }
    if (sum <= 1) {
        cout << 1 << endl;
        return 0;
    }

    const int maximum = 1 << 26;
    vector<int> minimum(maximum, INF<int>);
    minimum[0] = 0;
    for (int i = 0; i < N; i++) {
        const int v = value[i];
        int u = v;
        int mini = minimum[v];
        for (int d = 0; d < 26; d++) {
            if ((v >> d) & 1) {
                u = v - (1 << d);
            } else {
                u = v + (1 << d);
            }
            mini = min(mini, minimum[u] + 1);
        }
        minimum[v] = min(minimum[v], mini);
    }
    cout << minimum[value[N - 1]] << endl;


    return 0;
}
