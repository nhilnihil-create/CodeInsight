#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ll N ,M;
    cin >> N >> M;
    ll G[51][51] = {0};
    ll ans = 0;
    for(int i = 0; i < M; i++){
        ll tmp1, tmp2;
        ll ans = 0;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        G[tmp1][tmp2] = 1;
        G[tmp2][tmp1] = 1;
    }

    while(1){
        bool flag = false;
        for(int i = 0; i < N; i++){
            ll cnt = 0;
            ll tmp_i = -1;
            ll tmp_j = -1;
            for(int j = 0; j < N; j++){
                if(G[i][j] == 1){
                    cnt++;
                    tmp_i = i;
                    tmp_j = j;
                }
            }
            if(cnt == 1){
                ans++;
                flag = true;
                G[tmp_i][tmp_j] = 0;
                G[tmp_j][tmp_i] = 0;
            }
        }
        if(!flag) break;
    }

    cout << ans << endl;

}