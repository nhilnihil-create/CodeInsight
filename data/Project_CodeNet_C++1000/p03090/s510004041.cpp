#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    bool is_odd=false;
    if(N&1) {
        is_odd=true;
        N--;
    }
    int k=0;
    stringstream s;
    for(int i=1;i<=N;i++) {    
        int c = 1+N-i;
        for(int j=i+1;j<=N;j++) {
            if(j!=c) {
                k++;
                s << i << " " << j << "\n";
            }
        }    
    }

    if(is_odd) {
        for(int i=1;i<=N;i++) {
            k++;
            s << i << " " << N+1 << "\n";
        }
    }

    cout << k << "\n";
    cout << s.str();


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}