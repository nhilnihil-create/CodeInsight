#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
 
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int e[n+1] = {}, w[n+1] = {};
    e[0] = 0;
    w[0] = 0;
    for(int i = 1; i <= n;i++){
        e[i] = e[i-1];
        w[i] = w[i-1];
        if(s[i-1] == 'E'){
            e[i]++;
        }else{
            w[i]++;
        }
    }
    int ans = 300001;
    for(int i = 1; i <= n; i++){
        ans = min(ans,w[i-1] + e[n] - e[i]);
    }
    cout << ans << endl;
    return 0;
}