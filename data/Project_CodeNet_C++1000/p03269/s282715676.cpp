#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<size_t I,class H,class...T>struct TupleReaderWriter{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple_cat(tuple<H>(v),TupleReaderWriter<sizeof...(T)-1,T...>::r(i));}static void w(ostream&o,tuple<H,T...>&t,string d){TupleReaderWriter<I-1,H,T...>::w(o,t,d);o<<d<<get<I>(t);}};
template<class H,class...T>struct TupleReaderWriter<0,H,T...>{static tuple<H,T...> r(istream&i){H v;i>>v;return tuple<H>(v);}static void w(ostream&o,tuple<H,T...>&t,string d){o<<get<0>(t);}};
template<class...T>istream&operator>>(istream&i,tuple<T...>&t){t=TupleReaderWriter<sizeof...(T),T...>::r(i);return i;}
template<class...T>ostream&operator<<(ostream&o,tuple<T...>&t){string delim=" ";TupleReaderWriter<sizeof...(T)-1,T...>::w(o,t,delim);return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(auto&x:v)i>>x;return i;}
template<class T>ostream&operator<<(ostream&o,vector<T>&v){string delim="";for(auto&x:v)o<<delim<<x,delim=" ";return o;}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int x;fixprec(int d):x(d){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.x);}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
struct Edge {
    int from, to, len;
};
int main() {
    int L;
    cin >> L;
    vector<Edge> ans;
    int p = 1;
    for (int i = 0; i <= 16; i++) {
        ans.push_back({i, i + 1, 0});
        ans.push_back({i, i + 1, p});
        p *= 2;
    }
    // ~34本
    ans.push_back({17, 18, 0});
    ans.push_back({17, 18, p});
    ans.push_back({17, 18, 2 * p});
    // ~37本
    p *= 3;
    for(int i = 0; i < 2 && L >= p; i++) {
        L -= p;
        ans.push_back({18, 19, L});
    }
    // ~39本
    p /= 3;
    for(int i = 0; i < 2 && L >= p; i++) {
        L -= p;
        ans.push_back({17, 19, L});
    }
    // ~41本
    for(int i = 17; i >= 0; i--) {
        if (L >= p) {
            L -= p;
            ans.push_back({i, 19, L});
        }
        p /= 2;
    }
    // ~59本
    
    cout << 20 << " " << ans.size() << endl;
    for(auto x : ans) {
        cout << x.from + 1 << " " << x.to + 1 << " " << x.len << endl;
    }
    return 0;
}

