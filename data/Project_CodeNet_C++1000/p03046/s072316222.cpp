#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int M; cin >> M;
    ll K; cin >> K;
    if(K == 0){
        int cnt = 0;
        int loop = pow(2, M+1);
        rep(i, loop){
            if(i == loop-1) cout << cnt << endl;
            else cout << cnt << " ";
            if(i % 2 == 1) cnt++;
        }
    }
    else if(K <= pow(2, M)-1){
        if(M == 1){
            cout << -1 << endl;
            return 0;
        }
        cout << 0 << " " << K << " ";
        int mx = pow(2, M)-1;
        if(K < mx){
            rep(i, K) cout << i << " ";
            for(int i = K+1; i <= mx; i++) cout << i << " ";
            cout << K << " ";
            for(int i = mx; i >= K+1; i--) cout << i << " ";
            for(int i = K-1; i >= 1; i--){
                if(i == 1) cout << i << endl;
                else cout << i << " ";
            }
        }
        else{
            rep(i, K) cout << i << " ";
            for(int i = K; i >= 1; i--){
                if(i == 1) cout << 1 << endl;
                else cout << i << " ";
            }
        }
    }
    else cout << -1 << endl;
    return 0;
}