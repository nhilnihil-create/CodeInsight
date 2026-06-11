#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string S;
    cin >> S;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'A'){
            cnt++;
            if(ans < cnt){
               ans = cnt;
            }
        }
        else if(S[i] == 'C'){
            cnt++;
            if(ans < cnt){
               ans = cnt;
            }
        }
        else if(S[i] == 'G'){
            cnt++;
            if(ans < cnt){
               ans = cnt;
            }
        }
        else if(S[i] == 'T'){
            cnt++;
            if(ans < cnt){
               ans = cnt;
            }
        }
           else{
            cnt = 0;
            }
    }
    cout << ans << endl;
}
