#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    set<int> s;
    for (int i=0;i<4;++i){
        int N; cin >> N; s.emplace(N);
    }
    int ok=1;
    vector<int> v={1,9,7,4};
    for (int i=0;i<4;++i) if (!s.count(v[i])) ok=0;
    cout << (ok?"YES":"NO") << '\n';
}