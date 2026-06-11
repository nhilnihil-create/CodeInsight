#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}}; ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}

/*!* [intutil] *!*/
/*+* 整数演算いろいろ *+*/
i64 divceil(i64 a, i64 b) {
    return a / b + (a > 0 && a % b ? 1 : 0);
}
i64 logceil(i64 a, i64 b) {
    for(i64 i = 0, x = 1; a >= 2; x *= a, i++) if(x <= b) return i; return 0;
}
i64 gcd(i64 a, i64 b) {
    for (i64 c; a;) c = a, a = b % a, b = c; return b;
}
i64 lcm(i64 a, i64 b) {
    return (a / gcd(a, b) * b);
}
i64 pmod(i64 x, i64 m) {
    return (x % m + m) % m;
}
i64 sign(i64 x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int main() {
    const int INF = 1e8;
    int N;
    cin >> N;
    vector<i64> A(N);
    for(int i = 0; i < N; i++) {
        int p;
        cin >> p;
        A[p - 1] = i;
    }
    int S = 1, ans = N - 1;
    for(int i = 0; i < N - 1; i++) {
        if(sign(A[i + 1] - A[i]) > 0) S++;
        else {
            ans = min(ans, N - S);
            S = 1;
        }
    }
    ans = min(ans, N - S);
    cout << ans << endl;
    return 0;
}