#include<bits/stdc++.h>
using namespace std;

string T = "AKIHABARA";

int main(){
    string S;
    int Slen;
    int dp[10][10] = {};
    cin >> S;
    Slen = S.length();
    if(Slen > 9){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=Slen;j++){
            if(T[i-1] == S[j-1]){
                dp[i][j] = max({dp[i-1][j-1]+1, dp[i-1][j], dp[i][j-1]});
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    bool KIHBR = ((S.find('K') != string::npos) && (S.find('I') != string::npos) &&
                  (S.find('H') != string::npos) && (S.find('B') != string::npos) &&
                  (S.find('R') != string::npos));
    if(dp[9][Slen] == Slen && KIHBR){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}