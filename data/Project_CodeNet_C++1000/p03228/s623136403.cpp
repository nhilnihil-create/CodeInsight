#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

#define rep(i, e) for(int i = 0; i < e; i++)
#define repp(i, s, e) for(int i = s; i < e; i++)
#define MAX_N 100
#define Card_Max 36
#define p(a) printf("%d\n", a);
#define ll long long
#define ull unsigned long long
#define MAX 1e9
#define NIL -1
typedef pair<ll, ll> P;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    rep(i, K) {
        if(i % 2 == 0) {
            if(A % 2 == 1) {
                A--;
            }
            A /= 2;
            B += A;
        } else {
            if(B % 2 == 1) {
                B--;
            }
            B /= 2;
            A += B;
        }
    }
    cout << A << " " << B << endl;
}