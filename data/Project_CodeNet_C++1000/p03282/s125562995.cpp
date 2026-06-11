#include <iostream>
#include <string>
using namespace std;
int main(void){
    long long N;
    string S;
    cin >> S >> N;
    string ans;
    if(N == 1){
        ans = S[0];
    }
    else{
        if(S[0] != '1'){
            ans = S[0];
        }
        else{
            ans = '1';
            for(int i=1;i<N;i++){
                if(S[i] != '1'){
                    ans = S[i];
                    break;
                }
            }
        }
    }
    cout << ans;
}
