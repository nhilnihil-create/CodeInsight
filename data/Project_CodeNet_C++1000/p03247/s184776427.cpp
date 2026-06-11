#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N;
int X[1010];
int Y[1010];
ll X2[1010];
ll Y2[1010];

void solve_large(){
    int freq[2] = {};
    for(int i = 0; i < N; i++) freq[(X[i] + Y[i]) % 2] |= 1;
    // 和が奇数のみ or 偶数のみ でないと不可能
    if(freq[0] + freq[1] >= 2){
        cout << -1 << endl;
        return;
    }

    for(int i = 0; i < N; i++){
        X2[i] = X[i] + Y[i];
        Y2[i] = X[i] - Y[i];
    }

    vector<ll> D;
    // Dとしては 2^31 ぐらいまであれば十分なので、それで構築する
    for(int i = 0; i < 32; i++) D.push_back(1LL << i);
    reverse(D.begin(), D.end());
    if(X2[0] % 2 == 0) D.push_back(1);

    cout << (int)D.size() << endl;
    for(ll a : D) cout << a << " ";
    cout << endl;

    for(int i = 0; i < N; i++){
        vector<bool> ang[2];
        ll tmp[] = {X2[i], Y2[i]};
        for(int k = 0; k < 2; k++){
            const ll a = tmp[k];
            // 大きい数字から順番に利用する
            ll pos = 0;
            for(int j = 0; j < (int)D.size(); j++){
                if(a >= pos){
                    ang[k].push_back(true);
                    pos += D[j];
                }
                else{
                    ang[k].push_back(false);
                    pos -= D[j];
                }
            }
            if(pos < a) ang[k].push_back(true);
            else if(pos > a) ang[k].push_back(false);
        }
        for(int s = 0; s < (int)ang[0].size(); s++){
            if(ang[0][s] && ang[1][s]) cout << "R";
            else if(ang[0][s] && !ang[1][s]) cout << "U";
            else if(!ang[0][s] && ang[1][s]) cout << "D";
            else cout << "L";
        }
        cout << endl;
    }
    
}

void solve_small(){
    int freq[2] = {};
    for(int i = 0; i < N; i++){
        freq[(X[i] + Y[i]) % 2] |= 1;
        if(abs(X[i]) + abs(Y[i]) >= 21) return;
    }
    
    if(freq[0] + freq[1] >= 2){
        cout << -1 << endl;
    }
    else{
        int m = 0;
        if(freq[0] > 0) m = 40;
        else m = 39;

        cout << m << endl;
        for(int i = 0; i < m; i++){
            cout << 1 << " ";
        }
        cout << endl;

        for(int i = 0; i < N; i++){
            string ans;
            for(int j = 0; j < abs(X[i]); j++){
                if(X[i] >= 0) ans += 'R';
                else ans += 'L';
            }
            for(int j = 0; j < abs(Y[i]); j++){
                if(Y[i] >= 0) ans += 'U';
                else ans += 'D';
            }
            // 残った要素数で計算
            for(int j = 0; j < m - (abs(X[i]) + abs(Y[i])); j++){
                if(j % 2 == 0) ans += 'L';
                else ans += 'R';
            }
            cout << ans << endl;
        }
    }
}

int main(){

    cin >> N;
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    solve_large();

    return 0;
}
