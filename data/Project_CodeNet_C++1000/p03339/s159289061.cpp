#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int N;
    string S;
    cin >> N >> S;
    
    vector<int> lW(N), rE(N);
    for (int i = 1; i < N; i++) {
        lW[i] = lW[i-1];
        if(S[i-1] == 'W'){
            lW[i]++;
        }
    }
    for (int i=N-2; i>=0; i--) {
        rE[i] = rE[i+1];
        if (S[i+1] == 'E') {
            rE[i]++;
        }
    }
    int ans = N;
    for (int i=0; i < N; i++) {
        ans = min(ans, lW[i] + rE[i]);
    }
    cout << ans << endl;
}