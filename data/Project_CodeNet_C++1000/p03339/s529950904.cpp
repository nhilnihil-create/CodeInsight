#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int N;
    cin >> N;
    string S; 
    cin >> S;
    int left_W[N];
    int right_E[N];
    left_W[0] = (S[0] == 'W') ? 1 : 0;
    for(int i = 1; i < N; i++){
        if(S[i] == 'W'){
            left_W[i] = left_W[i-1] + 1;
        } else {
            left_W[i] = left_W[i-1];
        }
    }
    right_E[N-1] = (S[N-1] == 'E' ? 1 : 0);
    for(int i = N-2; i >=0 ; i--){
        if(S[i] == 'E'){
            right_E[i] = right_E[i+1] + 1;
        } else {
            right_E[i] = right_E[i+1];
        }
    }

    int ans = N;
    for(int i = 0; i <N; i++){
        int tmpans;
        if(i == 0){
            tmpans = right_E[1];
        } else if(i == N-1){
            tmpans = left_W[N-2];
        } else { 
            tmpans = left_W[i-1] + right_E[i+1];
        }
        if(tmpans < ans){
            ans = tmpans;
        }
    }
    cout << ans << endl;

}
