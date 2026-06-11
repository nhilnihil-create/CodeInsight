#include <bits/stdc++.h>
using namespace std;
using vi   = vector<int>;
using vvi  = vector<vi>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;
 
int main() {
    int N; cin >> N;
    vector<string> s(N); for (int i = 0; i < N; i++) cin >> s.at(i);
    int M; cin >> M;
    vector<string> t(M); for (int i = 0; i < M; i++) cin >> t.at(i);

    map<string, int> que;
    for (int i = 0; i < N; i++) {
        que[s.at(i)]++;
    }
    for (int i = 0; i < M; i++) {
        que[t.at(i)]--;
    }
    
    int ans = 0;
    for (auto ite = que.begin(); ite != que.end(); ite++) {
        if (ans < ite -> second) ans = ite -> second;
    }

    cout << ans << endl;

}