#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    string s;   cin >> s;

    int ans = s[0] - '0';
    bool c(true);
    for(int i=1;i<s.size();i++){
        if(s[i]!='9')   c = false;
    }
    if(!c){
        if (s.size() != 1)
        {
            ans += 9 * (s.size() - 1) - 1;
        }
    }else{
        ans += (s.size()-1)*9;
    }
    

    cout << ans << endl;

    return 0;
}