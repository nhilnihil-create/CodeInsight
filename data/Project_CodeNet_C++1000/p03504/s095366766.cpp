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
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)

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
    DRII(N, C);
    vector<pair<double, double>> CH[C];
    REP(i, N) {
        DRIII(s, t, c);
        CH[c-1].push_back({(double)s-0.5, (double)t});
    }
    // cout << "?" << endl;

    // merge interval in each channel;
    vector<pair<double, double>> SCH[C];
    REP(i, C) {
        // cout << "I:" << i << endl;
        if (SZ(CH[i]) > 0) {
            sort(CH[i].begin(), CH[i].end());
            double start = CH[i][0].first;
            double end = CH[i][0].second;
            REPP(j, 1, SZ(CH[i])) {
                if (CH[i][j].first < end) {
                    end = max(end, CH[i][j].second);
                } else {
                    SCH[i].push_back({start, end});
                    start = CH[i][j].first;
                    end = CH[i][j].second;      
                }
            }
            SCH[i].push_back({start, end});
        }
    }

    // cout << 111 << endl;

    // sort by value
    vector<pair<double, int>> programs;
    REP(i, C) {
        REP(j, SZ(SCH[i])) {
            programs.push_back({SCH[i][j].first, 0});
            programs.push_back({SCH[i][j].second, 1});
        }
    }
    // cout << 222 << endl;

    sort(programs.begin(), programs.end());
    
    int ans = 0;
    int count = 0;
    REP(i, SZ(programs)) {
        if (programs[i].second == 0) {
            count += 1;
        } else {
            count -= 1;
        }
        ans = max(ans, count);
        // cout << programs[i].first << " " << programs[i].second << endl;
    }

    cout << ans << endl;
    return 0;
}