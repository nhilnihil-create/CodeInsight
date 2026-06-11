#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    string S;
    int w;
    cin >> S >> w;
    
    for(int i=0;i<S.length();i+=w){
        cout << S[i];
    }
    
    cout << endl;
    
    return 0;
}
