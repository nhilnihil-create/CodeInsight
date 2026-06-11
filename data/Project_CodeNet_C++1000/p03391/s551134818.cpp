#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    i64 S = 0;
    i64 M = 1e14;
    bool equals = true;
    for(int i = 0; i < N; i++) {
        i64 a, b;
        cin >> a >> b;
        S += a;
        if(a > b) M = min(M, b);
        if(a != b) equals = false;
    }
    if(equals) M = S;
    cout << S - M << endl;

    return 0;
}