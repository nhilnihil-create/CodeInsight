#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    string S;
    cin >> S;
    string AD = "";
    for(int i = 0; i < S.size() - 1;){
        if(S.substr(i, 2) == "BC"){
            AD += 'D';
            i += 2;
        } else {
            AD += S[i];
            i++;
        }
    }
    i64 ans = 0, A = 0;
    for(int i = 0; i < AD.size(); i++){
        if(AD[i] == 'A') A++;
        else if(AD[i] == 'D') ans += A;
        else A = 0;
    }
    cout << ans << endl;
}