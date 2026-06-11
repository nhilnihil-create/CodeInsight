#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
const int MOD = 1e9+ 7;
const int INF = numeric_limits<int>::max() - (int)1e8;
const ll INFLL = numeric_limits<ll>::max() - (ll)1e17;

int main() {
    int N, K;
    cin >> N >> K;
    auto comp1 = [](pl &a, pl &b) {
        return a.second < b.second;
    };
    auto comp2 = [](pi &a, pi &b) {
        return a.second > b.second;
    };
    priority_queue<pl, vector<pl>, decltype(comp1)> remain(comp1);
    for (int i = 0; i < N; i++) {
        ll t, d;
        cin >> t >> d;
        remain.emplace(t, d);
    }
    map<int, int> use_sushi;
    ll score = 0;
    priority_queue<pi, vector<pi>, decltype(comp2)> use(comp2);
    for (int i = 0; i < K; i++) {
        auto now = remain.top();
        remain.pop();
        use_sushi[now.first]++;
        score += now.second;
        use.push(now);
    }
    ll ans = score + (ll) use_sushi.size() * (ll) use_sushi.size();
    while (!remain.empty()) {
        auto now = remain.top();
        remain.pop();
        if (use_sushi.find(now.first) != use_sushi.end()) continue;
        score += now.second;
        use_sushi[now.first]++;
        bool check = false;
        while (!use.empty()) {
            auto erase = use.top();
            use.pop();
            if (use_sushi[erase.first] == 1) continue;
            check = true;
            score -= erase.second;
            use_sushi[erase.first]--;
            break;
        }
        if (check) ans = max(ans, score + (ll) use_sushi.size() * (ll) use_sushi.size());
        else break;
    }
    cout << ans << endl;
}
