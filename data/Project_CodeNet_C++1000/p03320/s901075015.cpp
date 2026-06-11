// #include <bits/stdc++.h>
// #define WHOLE(v) (v).begin(), (v).end()
// #define REV_WHOLE(v) (v).rbegin(), (v).rend()
// using i64 = int64_t;
// using namespace std;
// template <size_t I, class H, class... T> struct TupleReaderWriter{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple_cat(tuple<H>(v),TupleReaderWriter<sizeof...(T)-1,T...>::r(i));}static void w(ostream&o,tuple<H,T...>&t,string d){TupleReaderWriter<I-1,H,T...>::w(o,t,d);o<<d<<get<I>(t);}};
// template <class H, class... T> struct TupleReaderWriter<0,H,T...>{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple<H>(v);}static void w(ostream&o,tuple<H,T...>&t,string d){o<<get<0>(t);}};
// template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
// template<class T>ostream&operator<<(ostream&o,vector<T>&v){string delim="";for(auto&x:v)o<<delim<<x,delim=" ";return o;}
// template <class... T> istream& operator>>(istream&i,tuple<T...>& t) { t = TupleReaderWriter<sizeof...(T), T...>::r(i); return i; }
// template <class... T> ostream& operator<<(ostream& o, tuple<T...>& t) { string delim = " "; TupleReaderWriter<sizeof...(T) - 1, T...>::w(o, t, delim); return o; }
// template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
// template<typename T> using vector2d = vector<vector<T>>;
// void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
// void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
// int main() {
//     i64 K;
//     cin >> K;
//     vector<pair<double, i64>> v, ans;
//     for(i64 i = 1; i < 1000000; i += 1) {
//         double d = 0;
//         i64 j = i * 1e10 + (1e10 - 1);
//         i64 tmp = j;
//         while(tmp) {
//             d += tmp % 10;
//             tmp /= 10;
//         }
//         v.push_back({double(j) / d, j});
//     }
//     sort(WHOLE(v));
//     for(auto x : v) {
//         if(ans.empty() || ans.back().second < x.second) {
//             ans.push_back(x);
//         }
//     }
//     for(auto x : ans) {
//         cout << x.second << ":" << x.first << endl;
//     }
//     return 0;
// }

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
    int K;
    cin >> K;
    set<i64> ans;
    vector<i64> p10(100);
    for(int b = 0; b < 16; b++) {
        int c = b > 10 ? b - 1 : b;
        p10[b] = b ? p10[b - 1] * 10 : 1;
        for(int i = max(1, c - 1); i < max(10, c * 10); i++) {
            ans.insert( (i + 1) * p10[b] - 1);
        }
    }
    int n = 0;
    for(auto x : ans) {
        if(n < K) {
            cout << x << endl;
            n++;
        }
    }
    return 0;
}