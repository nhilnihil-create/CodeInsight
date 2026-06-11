#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)

int main(){
    int M, K; cin >> M >> K;
    if(K >= (1 << M)) cout << -1 << endl;
    else if(M == 1){
        if(K == 1) cout << -1 << endl;
        else{
            cout << "0 0 1 1\n";
        }
    }
    else{
        cout << K << " ";
        rep(i, 0, (1 << M)){
            if(i == K) continue;
            cout << i << " ";
        }
        cout << K;
        rrep(i, 0, (1 << M)){
            if(i == K) continue;
            cout << " " << i ;
        }
        cout << endl;
    }
}