#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    string S, ans = "Yes";
    cin >> A >> B >> S;
    for(int i = 0; i < S.size(); ++i){
        if(i == A){
            if(!(S[i] == '-')){
                ans = "No";
                break;
            }
        }
        else if(!('0' <= S[i] && S[i] <= '9')){
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}