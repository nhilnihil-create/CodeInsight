#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    multiset<int> s;
    for (;N--;){
        int D; cin >> D;
        s.emplace(D);
    }
    int M; cin >> M;
    for (;M--;){
        int T; cin >> T;
        if (!s.count(T)){cout << "NO" << '\n'; return 0;}
        s.erase(s.lower_bound(T));
    }
    cout << "YES" << '\n';
}