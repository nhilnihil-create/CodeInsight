// g++ -std=c++11 test.cpp && ./a.out
// g++ -std=c++11 test.cpp && ./a.out < test.txt

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>

using namespace std;

#define INF (1<<29)
#define SZ(X) ((int)(X).size())
#define PRINT(A) {for (auto it=A.begin(); it != A.end(); ++it) {cout << *it << ' ';} cout << endl;}
#define SUM(A) accumulate(A.begin(), A.end(), 0)
#define MAX(A) *max_element(A.begin(), A.end())
#define BIT_LENGTH(N) floor(log2(N)) + 1
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = N-1; I >= 0 ; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RREPP(I, A, B) for (int I = A; I > (B); --I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
typedef vector<int> VI;
typedef map<int, int> MII;
typedef set<int> SI;
typedef vector<string> VS;
typedef vector<vector<int> > VVI;

void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }

int main() {
    int N;
    int C;
    _R(N);
    _R(C);

    int S[N];
    int T[N];
    int CH[N];
    REP(i, N) {
        int s, t, c;
        _R(s);
        _R(t);
        _R(c);
        S[i] = s;
        T[i] = t;
        CH[i] = c-1;
    }

    const int MAX_SIZE = 200002;
    int accu[MAX_SIZE] = {0};
    REP(i, C) { // deal with channel i;
        int channels[MAX_SIZE] = {0};
        REP(j, N) {
            if (CH[j] == i) {
                REPP(k, S[j]*2 - 1, T[j]*2) {
                    channels[k] = 1;
                }
            }
        }
        REP(j, MAX_SIZE) {
            if (channels[j] > 0) {
                accu[j] += 1;
            }
        }
    }

    int ans = 0;
    REP(i, MAX_SIZE) {
        ans = max(ans, accu[i]);
    }
    cout << ans << endl;
    return 0;
}