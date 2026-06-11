#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    map<int, int> m;
    rep(i, N){
        int a; cin >> a;
        m[a]++;
    }
    priority_queue<int> pq;
    for (auto p : m){
        auto value = p.second;
        pq.push(value);
    }

    int n = 0;
    rep(i, K){
        int x = pq.top(); pq.pop();
        n += x;
        if(pq.empty())break;
    }
    if(pq.empty()){
        cout << 0 << endl;
    } else {
        cout << N - n << endl;
    }

    return 0;
}