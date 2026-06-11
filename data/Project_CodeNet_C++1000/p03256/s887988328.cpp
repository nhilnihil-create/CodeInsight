#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - 1e8;
const ll INFLL = numeric_limits<ll>::max() - 1e17;

int main() {
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    s = "0" + s;
    vector<pi> count(N + 1, {0, 0});
    vector<set<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for (int i = 1; i <= N; i++) {
        for (auto temp : graph[i]) {
            if (s[i] == 'A') count[temp].first++;
            else count[temp].second++;
        }
    }
    queue<int> explore;
    set<int> wrong;
    auto judge = [&](int idx) {
        return (count[idx].first == 0 || count[idx].second == 0);
    };
    for (int i = 1; i <= N; i++) if (judge(i)) explore.push(i);
    while (!explore.empty()) {
        int now = explore.front();
        explore.pop();
        wrong.insert(now);
        for (int temp : graph[now]) {
            if (s[now] == 'A') count[temp].first--;
            else count[temp].second--;
        }
        set<int> step = graph[now];
        for (int temp : graph[now]) if (judge(temp)) explore.push(temp);
        for (int temp : step) {
            graph[temp].erase(now);
            graph[now].erase(temp);
        }
    }
    cout << (wrong.size() == N ? "No" : "Yes") << endl;
}