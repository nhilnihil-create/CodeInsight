#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    mat graph(N, vec()), from(N, vec());
    vec h(N, 0);
    Rep (i, N-1+M) {
        ll A, B;
        cin >> A >> B;
        A--; B--;
        graph[A].push_back(B);
        from[B].push_back(A);
        h[B]++;
    }

    stack<ll> st;
    Rep (i, N) {
        if (h[i] == 0) st.push(i);
    }

    vec topological;
    while (st.size()) {
        ll i = st.top(); st.pop();
        topological.push_back(i);
        for (auto &j : graph[i]) {
            h[j]--;
            if (h[j] == 0) st.push(j);
        }
    }

    vec order(N);
    Rep (i, N) {
        order[topological[i]] = i;
    }

    // Rep (i, N) {
    //     cout << topological[i] << " \n"[i==N-1];
    // }

    // Rep (i, N) {
    //     cout << order[i] << " \n"[i==N-1];
    // }

    vec mother(N);
    for (ll i = N-1; i >= 0; i--) {
        ll a = -1;
        for (ll e : from[topological[i]]) {
            chmax(a, order[e]);
        }
        if (a > -1) mother[topological[i]] = topological[a];
        else mother[topological[i]] = -1;
    }

    Rep (i, N) {
        cout << mother[i] + 1 << "\n";
    }
}