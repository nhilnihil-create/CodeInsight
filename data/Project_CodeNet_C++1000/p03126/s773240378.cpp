#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N, M,ans = 0;
    cin >> N >> M;
    vector<ll> score(M,0);
    for(int i = 0; i < N; i++){
        ll K;
        cin >> K;
        for(int j = 0; j < K; j++){
            ll tmp;
            cin >> tmp;
            tmp--;
            score[tmp]++;
        }
    }
    for(int i = 0; i < M; i++){
        if(score[i] == N){
            ans++;
        }
    }
    cout << ans << endl;
}