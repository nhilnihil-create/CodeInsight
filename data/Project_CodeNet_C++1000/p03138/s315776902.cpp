#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N, K, X, b[41];
vector<int> kb ={-1};
int main(){
    cin >> N >> K;
    for(int i = 0; i < 40; i++){
        if((K >> i) & 1) kb.push_back(i);
    }
    for(int i = 0; i < N; i++){
        ll A;
        cin >> A;
        for(int j = 0; j < 40; j++){
            if((A >> j) & 1) b[j]++;
        }
    }
    vector<ll> plu[4];
    for(int i = 0; i < kb.size() - 1; i++){
        ll p = 0;
        for(int j = kb[i] + 1; j < kb[i + 1]; j++){
            p += max(b[j], N - b[j]) * ((ll)1 << j);
        }
        plu[0].push_back(p);
        
        p = b[kb[i + 1]] * ((ll)1 << (kb[i + 1]));
        plu[1].push_back(p);

        p = 0;
        for(int j = kb[i] + 1; j < kb[i + 1]; j++){
            p += b[j] * ((ll)1 << j);
        }
        plu[2].push_back(p);

        p = (N - b[kb[i + 1]]) * ((ll)1 << (kb[i + 1]));
        plu[3].push_back(p);
    }

    ll ans = 0;
    for(int i = plu[1].size();i >= 0; i--){
        ll res = 0;
        for(int j = plu[1].size() - 1; j >= i; j--){
            res += plu[3][j] + plu[2][j];
        }
        if(i != 0) res += plu[1][i - 1] + plu[0][i - 1];

        for(int j = 0; j < i - 1; j++){
            res += max(plu[1][j], plu[3][j]);
            res += plu[0][j];
        }
        ans = max(ans, res);
    }
    for(int i = kb[kb.size() - 1] + 1; i < 40; i++){
        ans += b[i] * ((ll)1 << i);
    }
    cout << ans << endl;
    return 0;
}