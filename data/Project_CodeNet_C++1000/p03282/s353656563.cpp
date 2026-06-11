#include <iostream>
#include <string>
using namespace std;
const long long INF = 5000000000000000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S; cin >> S;
    long long K; cin >> K;
    for(int i = 0; i < S.size(); ++i){
        if(S[i] == '1'){
            K--;
            if(K == 0) {
                cout << 1 << endl;
                return 0;
            }
            continue;
        }
        cout << S[i] << endl;
        break;
    }
    return 0;
}