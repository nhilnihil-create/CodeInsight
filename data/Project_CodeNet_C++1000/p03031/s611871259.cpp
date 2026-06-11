#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    int N,M,K,S; cin >> N >> M;
    vector<vector<int>> bulb(M);
    vector<int> re(M);
    for(int i=0;i<M;i++){
        cin >> K;
        for(int j=0;j<K;j++){
            cin >> S; S--;
            bulb[i].push_back(S);
        }
    }
    
    for(int i=0;i<M;i++){ cin >> re[i]; }
    
    ll ans = 0;
    for (int bits = 0; bits < (1 << N); bits++) {  //スイッチの個数
        bool ok = true;
        for (int i = 0; i < M; i++) {  //電球の個数
            int sum = 0;
            for (auto v : bulb[i]) {    //電球の個数が違うので拡張for文
                if (bits & (1<<v)) ++sum;   //ビットが立っているところはカウント
            }
            if (sum % 2 != re[i]) ok = false; //すべての電球に対してスイッチの偶奇が等しいか確認
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}