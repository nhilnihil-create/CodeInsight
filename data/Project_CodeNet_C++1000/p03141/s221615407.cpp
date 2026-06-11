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
#include <tuple>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main ()
{
    int N;
    cin >> N;

    priority_queue<tuple<ll,ll>> que;
    vector<ll> iA,iB;
    REP(i,N) {
        ll A,B;
        cin >> A >> B;
        iA.push_back(A);
        iB.push_back(B);
        que.emplace(A + B, i);
    }

    ll A = 0, B = 0;
    REP(i,N) {
        ll val,idx;
        tie(val,idx) = que.top();
        que.pop();
        if (i % 2 == 0) A += iA[idx];
        if (i % 2 == 1) B += iB[idx];
    }

    cout << A - B << endl;

    return 0;
}
