#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif




#define int long long
#define rng(i,l,r) for(size_t i=(l);i<(r);++i)
#define rep(i,n) rng(i,0,n)
#define gnr(i,l,r) for(size_t i=(r)-1;i>=(l);i--)
#define per(i,b) gnr(i,0,b)
#define ALL(obj) (obj).begin(), (obj).end()   //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend()//...,3,2,1

using namespace std;


//constant
const int MOD = 1e9+7;
const int INF = 1e18;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1,1,0,-1,-1,-1,0,1};
const int dy8[8] = {0,1,1,1,0,-1,-1,-1};
const double pi = acos(-1);


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int gcd(int a,int b){return b?gcd(b,a%b):a;}
//*max_element(ALL(vector))
//count(ALL(vector),num) -> n
//memset(obj,value,sizeof(obj));

int n,a,b,c;
vector<int> l;
#define A 0
#define B 1
#define C 2
#define N 3
int ans = INF;

void dfs(string s){
    if(s.size()==n){
        int numa,numb,numc;
        numa = count(ALL(s),'A');
        numb = count(ALL(s),'B');
        numc = count(ALL(s),'C');
        if(min({numa,numb,numc})==0) return;
        
        int cjA = 10*(numa-1);//cost joint A
        int cjB = 10*(numb-1);
        int cjC = 10*(numc-1);
        
        int lnA,lnB,lnC; lnA=lnB=lnC=0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='A') lnA += l[i];
            if(s[i]=='B') lnB += l[i];
            if(s[i]=='C') lnC += l[i];
        }
        
        ans = min(ans,cjA+cjB+cjC + abs(a-lnA)+abs(b-lnB)+abs(c-lnC));
        
        return;
    }
    
    dfs(s+'A');
    dfs(s+'B');
    dfs(s+'C');
    dfs(s+'N');
    
    
}

void solve(){
    
    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> a >> b >> c;
    l.resize(n);
    rep(i,n) cin >> l[i];
    
    dfs("");
    
    
    cout << ans << endl;
    
}





signed main() {
    solve();
    return 0;
}


