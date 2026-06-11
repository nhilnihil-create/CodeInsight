#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int N;
    string s;
    cin >> N >> s;
    
    int R=0,B=0;
    for(int i=0;i<N;i++){
        if(s[i]=='R')R++;
        else B++;
    }
    
    if(R>B) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

