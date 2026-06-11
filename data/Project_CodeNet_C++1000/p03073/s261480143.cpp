#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    string S;
    cin >> S;
    int N = S.length();
    int ans = 0;
    for(int i=0;i+1<N;i++){
        if(S[i] == S[i+1]){
            ans++;
            if(S[i+1] == '0'){
                S[i+1] = '1';
            }
            else{
                S[i+1] = '0'; 
            }
        }
    }
    cout << ans << endl;
}
