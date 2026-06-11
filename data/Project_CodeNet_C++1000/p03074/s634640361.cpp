#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    vector<int> stand, sakadachi;
    char now = '2';
    int counter = 1;
    rep(i, N){
        if(S[i] != now){
            if(i != 0){
                if(now == '1'){
                    sakadachi.push_back(counter);
                } else {
                    stand.push_back(counter);
                }
            }
            now = S[i];
            counter = 1;
            if(i == N-1){
                if(now == '1'){
                    sakadachi.push_back(counter);
                } else {
                    stand.push_back(counter);
                }
            }
        } else {
            counter++;
            if(i == N-1){
                if(now == '1'){
                    sakadachi.push_back(counter);
                } else {
                    stand.push_back(counter);
                }
            }
        }
    }
    if(S[N-1] == '0'){
        sakadachi.push_back(0);
    }
    if(S[0] == '0'){
        sakadachi.insert(sakadachi.begin(), 0);
    }


    if(K >= stand.size()){
        cout << N << endl;
        return 0;
    }

    vector<int> S0(stand.size()+1);
    vector<int> S1(sakadachi.size()+1);
    S0[0] = 0;
    S1[0] = 0;

    for (int i = 1; i <= stand.size(); i++){
        S0[i] = S0[i-1] + stand[i-1];
    }
    for (int i = 1; i <= sakadachi.size(); i++){
        S1[i] = S1[i-1] + sakadachi[i-1];
    }

    int ans = 0;
    for (int i = 0; i <= stand.size()-K; i++){
        int x = S0[K+i] - S0[i] + S1[K+i+1] - S1[i];
        ans = max(ans, x);
    }
    

    cout << ans << endl;

    return 0;
}