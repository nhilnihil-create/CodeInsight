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
    cin >> N;
    int X = -1;
    for(int i = 1; i < 1e4; i++) {
        if(N == (i * (i - 1)) / 2) {
            X = i;
        }
    }
    if(X < 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<vector<int>> S(X);
    int j = 1;
    for(int n = X - 1; n > 0; n--) {
        for(int i = 0; i < n; i++) {
            S[n].push_back(j);
            S[i].push_back(j);
            j++;
        }
    }
    cout << X << endl;
    for(int i = 0; i < X; i++) {
        cout << S[i].size() << " " << S[i] << endl;
    }
    return 0;
}