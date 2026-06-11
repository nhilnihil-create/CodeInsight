#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N; cin >> N;
    vector<string > s(N);
    for (int i=0; i<N; i++) cin >> s[i];
    
    int ans = 0;
    int ab = 0;
    int a = 0;
    int b = 0;
    for (int i=0; i<N; i++){
        int n = s[i].size() - 1;
        if (s[i][0] == 'B' && s[i][n] == 'A'){
            ab++;
        }else if(s[i][0] == 'B'){
            b++;
        }else if(s[i][n] == 'A'){
            a++;
        }
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<s[i].size() - 1; j++){
            if(s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }
    }
    // cout << ab << " " << a << " " << b << " " << ans <<  endl;
    int p = 0;
    if (ab > 0){
        ans += ab - 1;
        p = 1;
    }
    
    ans += min(a, b);
    if (a + b >  0 && p == 1) ans += 1;
    
    cout << ans << endl;
    
}
