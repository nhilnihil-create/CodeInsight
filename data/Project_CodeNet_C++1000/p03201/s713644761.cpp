#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
int main() {
    int N;
    cin >> N;
    map<i64, int, greater<i64>> x;
    for(int i = 0; i < N; i++) {
        i64 a;
        cin >> a;
        x[a]++;
    }
    int ans = 0;
    for(auto p : x) {
        i64 a; int n;
        tie(a, n) = p;
        if( (a & (a - 1)) == 0) {
            ans += n / 2;
        } else {
            int s = 1;
            while(s < a) s <<= 1;
            int m = x[s - a];
            x[s - a] -= min(n, m);
            ans += min(n, m);
        }
    }
    cout << ans << endl;
    return 0;
}