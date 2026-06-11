#include <bits/stdc++.h>
using namespace std;

auto& scan_in = std::cin;

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
//Cスタイルの入出力とC++スタイルの入出力の同期を切る操作
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { scan_in >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest& ...rest) { scan_in >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int w_=0; w_<n; ++w_){MACRO_VEC_ROW_Scan(w_, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest& ...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { scan_in >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest& ...rest) { scan_in >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)scan_in>>i;

// output
template<typename T>void MACRO_OUT(const T t) { std::cout << t; }
template<typename First, typename...Rest>void MACRO_OUT(const First first, const Rest...rest) { std::cout << first << " "; MACRO_OUT(rest...); }
#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";

// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define RREP(w, n) RFOR(w, 0, n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)


#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")

template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if (f) Out(y); else Out(n); }

signed main() {
    INIT;


    // ⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎⬇︎
    VAR(int, n, y);
    for(int a=0; a<=n; ++a){
        for(int b=0; a+b<=n; ++b){
            int c = n - a - b;
            int x = a * 10000 + b * 5000 + c * 1000;
            if(x == y){
                cout << a << ' ' << b << ' ' << c << endl;
                return 0;
            }
        }
    }
 
    cout << "-1 -1 -1" << endl;
  
	return 0;
}
