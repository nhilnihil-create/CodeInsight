#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    veci S(N-1),C(N-1),F(N-1);
    REP(i,N-1) cin >> C[i] >> S[i] >> F[i];
    veci ans(N);
    for(int i = 0; i < N; i++) {
        int t = 0;
        for(int j = i; j < N-1; j++) {
            if(t < S[j]) t = S[j] + C[j];
            else if(t%F[j] == 0) t = t + C[j];
            else t = t+F[j]-(t%F[j]) + C[j];
        }
        cout << t << endl;
    }
}
