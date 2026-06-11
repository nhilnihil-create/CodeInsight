#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N, M; cin >> N >> M;
    string s, t; cin >> s >> t;
    int L = N / __gcd(N, M) * M;
    int g = __gcd(N, M);
    for(int i = 0, j = 0; i < N; i += N / g, j += M / g){
        if(s[i] != t[j]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << L << endl;
}