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
using P = pair<int, int>;
int main() {
    int N, M;
    cin >> N;
    cout << N * (N - 1) / 2 - N / 2 << endl;
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(i + j != N / 2 * 2 + 1) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}

