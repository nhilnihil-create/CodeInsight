#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (ll i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

int H,W,N;
int X[200010];
int Y[200010];
int T[200010];

int main ()
{
    cin >> H >> W >> N;
    REP(i,N) cin >> X[i] >> Y[i];
    REP(i,N) {
        X[i]--;
        Y[i]--;
    }

    fill(T, T + 200010, 1e9);
    REP(i,N) T[X[i]] = min(T[X[i]], Y[i]);
    set < pair < int,int > > used;
    REP(i,N) used.insert(make_pair(X[i], Y[i]));
        
    int Aoki = 0;
    int Takahashi = 0;
    int pre = -10;
    for (int i = 1; i < H; i += 1) {
        if (T[i] <= Aoki) {
            cout << i << endl;
            return 0;
        }
        if (T[i] != Aoki + 1) {
            Aoki++;
        }
    }

    cout << H << endl;

    return 0;
}


