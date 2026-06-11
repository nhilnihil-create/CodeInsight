#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int a=0,b=n-1,ans=0;
    bool flag = true;
    while(b-a>0){
        if(s[a]==s[b]){
            a++;
            b--;
            continue;
        } 
        else{
            ans++;
            if(s[a] == 'x') a++;
            else if(s[b] == 'x') b--;
            else{
                flag = false;
                break;
            } 
        }
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
}