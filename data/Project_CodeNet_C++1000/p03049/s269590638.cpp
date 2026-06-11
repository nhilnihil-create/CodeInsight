#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    long long ans= 0;
    long long cntab = 0, cnta = 0, cntb = 0;
    for(int i = 0; i < N; i++){
        if(S[i][0] == 'B' && S[i][S[i].size() - 1] == 'A') cntab++;
        else if(S[i][0] == 'B') cntb++;
        else if(S[i][S[i].size() - 1] == 'A') cnta++;
        for(int j = 0; j < S[i].size(); j++){
            if(j < S[i].size() - 1 && S[i][j] == 'A' && S[i][j + 1] == 'B') ans++;
        }
    }
    if(cntab == 0) ans += min(cnta, cntb);
    else if(cnta == 0 && cntb == 0) ans += cntab - 1;
    else if(cnta == 0 || cntb == 0) ans += cntab;
    else ans += cntab + min(cnta, cntb);
    cout << ans << endl; 
}
