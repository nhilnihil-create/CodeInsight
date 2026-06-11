#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> C(N-1),S(N-1),F(N-1);
    for(int i = 0; i < N-1; i++) cin >> C[i] >> S[i] >> F[i];
    
    for(int i = 0; i < N; i++){
        int ans = 0;
        
        for(int j = i; j < N-1; j++){
            if(ans <= S[j]) ans = S[j];
            else if(ans % F[j] == 0);
            else ans = ans + (F[j] - ans%F[j]);
            ans += C[j];
        }
        
        cout << ans << endl;
        
        
    }
    
    
}


