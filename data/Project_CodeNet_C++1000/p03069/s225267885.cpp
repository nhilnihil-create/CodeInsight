#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int solve(void){
    int N;
    string S;
    cin >> N >> S;
    int white=0,black=0;
    for(int i=0;i<N;i++){
        if(S[i] == '.')white++;
        else black++;
    }
    if(white == N || black == N){
        return 0;
    }
    int ans = min(white,black);
    black = 0;
    for(int i=0;i+1<N;i++){
        if(S[i] == '.')white--;
        if(S[i] == '#')black++;
        if(S[i] == '.' && S[i+1] == '#'){
            ans = min(ans,white+black);
        }
    }
    return ans;
    
}
int main(void){
    int ans = solve();
    cout << ans << endl;
}
