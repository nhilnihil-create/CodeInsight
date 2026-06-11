#include <iostream>

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<string>
#include <cstdlib>
#include <typeinfo>

#define REP(i, n) for(int i=0;i<n;i++)
#define REP2(i, s, n) for(int i=s;i<n;i++)
#define REP_1(i, n) for(int i=1;i<n+1;i++)
#define bitSearch(bit, n) for(int bit = 0; bit < (1 << N); bit++)
using namespace std;

template<class T>
void print(const T &value) {
    std::cout << value << std::endl;
}

void yesno(bool a) { if (a)cout << "Yes" << endl; else cout << "No" << endl; }

void YESNO(bool a) { if (a)cout << "YES" << endl; else cout << "NO" << endl; }

typedef long long ll;
typedef unsigned long ul;
typedef long double ld;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//ll INF = 10000000;
//ll mod = 1000000007;//10^9+7

//using Graph = vector<vector<pair<int, int>>>;
//Graph G(100100);


//番号ズレ注意！！
int main() {
    int ans = 0;
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B > 2 * C) {
        int N = min(X, Y);
        ans += 2 * N * C;
        X -= N;
        Y -= N;
    }
    if (A > 2 * C) {
        ans += 2 * X * C;
        X = 0;
    }
    if (B > 2 * C) {
        ans += 2 * Y * C;
        Y = 0;
    }
    ans += X * A + Y * B;
    print(ans);
}
