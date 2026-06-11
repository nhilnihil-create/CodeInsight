#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template <size_t I, class H, class... T> struct TupleReaderWriter{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple_cat(tuple<H>(v),TupleReaderWriter<sizeof...(T)-1,T...>::r(i));}static void w(ostream&o,tuple<H,T...>&t,string d){TupleReaderWriter<I-1,H,T...>::w(o,t,d);o<<d<<get<I>(t);}};
template <class H, class... T> struct TupleReaderWriter<0,H,T...>{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple<H>(v);}static void w(ostream&o,tuple<H,T...>&t,string d){o<<get<0>(t);}};
template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
template<class T>ostream&operator<<(ostream&o,vector<T>&v){string delim="";for(auto&x:v)o<<delim<<x,delim=" ";return o;}
template <class... T> istream& operator>>(istream&i,tuple<T...>& t) { t = TupleReaderWriter<sizeof...(T), T...>::r(i); return i; }
template <class... T> ostream& operator<<(ostream& o, tuple<T...>& t) { string delim = " "; TupleReaderWriter<sizeof...(T) - 1, T...>::w(o, t, delim); return o; }
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    i64 C;
    cin >> N >> C;
    vector<i64> X(N), V(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> V[i];
    }
    i64 ans = 0;
    for(int b = 0; b < 2; b++) {
        vector<i64> F(N, 0), B(N, 0);
        i64 e = 0;
        for(int i = 0; i < N; i++) {
            e += V[i] - (X[i] - (i ? X[i - 1] : 0));
            F[i] = max(i ? F[i - 1] : 0, e);
        }
        e = 0;
        for(int i = N - 1; i >= 0; i--) {
            e += V[i] - ((i < N - 1 ? X[i + 1] : C) - X[i]);
            B[i] = max(i < N - 1 ? B[i + 1] : 0, e);
        }

        for(int i = 0; i < N - 1; i++) {
            ans = max({ans, F[i], F[i] - X[i] + B[i + 1]});
        }

        ans = max(ans, F.back());

        reverse(WHOLE(X)), reverse(WHOLE(V));
        for(auto &x : X) x = C - x;
    }

    cout << ans << endl;

    return 0;
}