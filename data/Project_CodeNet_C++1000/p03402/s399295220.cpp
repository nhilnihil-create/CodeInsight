#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

// void chmod(ll &M){
//     if(M >= mod) M %= mod;
//     else if(M < 0){
//         M += (abs(M)/mod + 1)*mod;
//         M %= mod;
//     }
// }

int main(){
    int a, b; cin >> a >> b;
    --a; --b;
    vector<vector<char>> field(100, vector<char>(100));
    for(int i=0; i<50; ++i) for(int j=0; j<100; ++j) field[i][j] = '#';
    for(int i=50; i<100; ++i) for(int j=0; j<100; ++j) field[i][j] = '.';

    for(int i=0; i<50; i+=2){
        if(a == 0) break;
        for(int j=0; j<100; j+=2){
            if(a == 0) break;
            field[i][j] = '.';
            --a;
        }
    }

    for(int i=51; i<100; i+=2){
        if(b == 0) break;
        for(int j=0; j<100; j+=2){
            if(b == 0) break;
            field[i][j] = '#';
            --b;
        }
    }


    printf("100 100\n");
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            cout << field[i][j];
        }
        cout << endl;
    }

    return 0;
}
