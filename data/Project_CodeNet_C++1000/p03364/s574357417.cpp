#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for(int i=0;i<N;i++){
        cin >> S[i];
    }
    ll ans =0;
    for(int k=(-N+1);k<N;k++){
        bool ok = true;
        for(int y=0;y<N;y++)for(int x=0;x<N;x++){
            if(S[y][x] != S[(x+N-k)%N][(y+N+k)%N]){
                ok = false;
                break;
            }
        }
        if(ok){
            ans += (N-abs(k));
        }
    }
    cout << ans << endl;


    return 0;
}