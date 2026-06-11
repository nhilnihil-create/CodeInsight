#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES": "NO") << endl;}
void R_YesNo(bool p) { cout << (p ? "Yes": "No") << endl;}
int main() {
    int N, K;
    cin >> N >> K;
    // おいしい寿司
    map<int, i64> best;
    // 消去候補の寿司(まずい順)
    rev_priority_queue<pair<i64, int>> dust;
    // あまりものの寿司(おいしい順)
    priority_queue<pair<i64, int>> rest;

    for(int i = 0; i < N; i++) {
        int t; i64 d;
        cin >> t >> d;
        rest.push({d, t});
    }
    // 答えと候補
    i64 ans = 0, pt = 0;

    // おいしい K 個だけ取り出す
    for(int i = 0; i < K; i++) {
        int t; i64 d;
        tie(d, t) = rest.top(); rest.pop();
        pt += d;
        if(best.count(t)) {
            dust.push({d, t});
        } else {
            best[t] = d;
        }
    }
    ans = max<i64>(ans, pt + best.size() * best.size());

    bool end_flag = false;

    for(int x = best.size() + 1; x <= K; x++) {
        int t; i64 d;
        // 別の種類の寿司が来るまで取り出す
        do {
            end_flag = rest.size() == 0;
            if(end_flag) break;
            tie(d, t) = rest.top(); rest.pop();
        } while(best.count(t));
        if(end_flag) break;
        
        best[t] = d;
        pt += d - dust.top().first; dust.pop();
        ans = max<i64>(ans, pt + best.size() * best.size());
    }

    cout << ans << endl;
    return 0;
}