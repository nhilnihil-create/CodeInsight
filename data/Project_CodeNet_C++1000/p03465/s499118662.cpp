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

/*!* [itertools] *!*/
/*+* イテレータの操作 *+*/
template<class I,class V=typename I::value_type>V sum_up(const I&l,const I&r){V v;for(I i=l;i!=r;i++)v=i==l?*i:v+*i;return v;}
template<class I,class T=iterator_traits<I>>I operator+(I it,int n){for(int i=0;i<n;i++)it++;return it;}
template<class I,class T=iterator_traits<I>>I operator-(I it,int n){for(int i=0;i<n;i++)it--;return it;}

int main() {
    int N;
    const int M = 4e6;
    cin >> N;
    vector<int> A(N);
    for(int &a : A) cin >> a;
    bitset<M + 1> dp;
    dp[0] = true;
    for(int i = 0; i < N; i++) {
        dp |= dp << A[i];
    }
    int S = sum_up(WHOLE(A));
    int ans = 0;
    for(int j = M; 2 * j >= S; j--) {
        if(dp[j]) ans = j;
    }
    cout << ans << endl;
    return 0;
}