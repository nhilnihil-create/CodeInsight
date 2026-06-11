#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N, M;
    cin >> N;
    map< string, int> m;
    rep(i, N){
        string S;
        cin >> S;
        m[S]++;
    }
    cin >> M;
    rep(i, M){
        string S;
        cin >> S;
        m[S]--;
    }
    int max = 0;
    for(auto i: m){
        chmax(max, i.second);
    }
    cout << max << endl;



}