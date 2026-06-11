#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

signed main(){
    int n; cin >> n;
    
    vector<int> L(50), R(50);
    L[0] = 0; R[0] = 1;
    
    int digit = 1;
    
    for(int i = 1; i<50; i++){
        if(L[i-1] <= n && n <= R[i-1]){
            digit = i-1;
            break;
        }
        L[i] = L[i-1] + min(0, (signed)pow(-2,i));
        R[i] = R[i-1] + max(0, (signed)pow(-2,i));
    }
    
    string ans = "";
    for(int i = digit; i>=0; i--){
        int prev = n - pow(-2,i);
        if(L[i] <= prev && prev <= R[i]){
            ans += '1';
            n = prev;
        }else{
            ans += '0';
        }
    }
    
    cout << ans << endl;
}